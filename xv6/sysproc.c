#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)  //// Aquí deberíamos poner int?? 
{

  int exit_status;
  argint(0, &exit_status);  // Almacenamos el primer argumento en exit_status 
/**
  if(exit_status < 0) Se comprueba si se ha pasado algún argumento ??? 
      exit(0);*/
  exit(exit_status);
  
  return 0;  // not reached
}

int
sys_wait(void)
{
  int* status;
  if (argptr(0, (void**) &status,sizeof(int*)) < 0)
    return -1;

  return wait(status);
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

// int date(struct rtcdate*)
int
sys_date(void)
{
    struct rtcdate *r;
    // obtener el puntero que el usuario puso originalmente
  //Funciones argXXXX
  //argint -> entero
  //argfd -> descriptor de fichero
  //argptr ->  puntero
  if (argptr(0, (void **)&r, sizeof(struct rtcdate *)) < 0)
  {
    return -1;
  };

  cmostime(r);
  return 0;
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;


  myproc()->sz += n;

//  if(growproc(n) < 0)
//    return -1;
// 
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
