struct stat;
struct rtcdate;

// system calls
extern int chdir(const char*);
extern int close(int);
extern int date(struct rtcdate *);
extern int dup(int);
extern int dup2(int, int);
extern int exec(char*, char**);
extern int exit(int) __attribute__((noreturn));
extern int fork(void);
extern int fstat(int fd, struct stat*);
extern int getpid(void);
extern int kill(int);
extern int link(const char*, const char*);
extern int mkdir(const char*);
extern int mknod(const char*, short, short);
extern int open(const char*, int);
extern int pipe(int*);
extern int read(int, void*, int);
extern char* sbrk(int);
extern int sleep(int);
extern int unlink(const char*);
extern int uptime(void);
extern int wait(int);
extern int write(int, const void*, int);
// ulib.c
extern int stat(const char*, struct stat*);
extern char* strcpy(char*, const char*);
extern void *memmove(void*, const void*, int);
extern char* strchr(const char*, char c);
extern int strcmp(const char*, const char*);
extern void printf(int, const char*, ...);
extern char* gets(char*, int max);
extern uint strlen(const char*);
extern void* memset(void*, int, uint);
extern void* malloc(uint);
extern void free(void*);
extern int atoi(const char*);

#define NULL 0
