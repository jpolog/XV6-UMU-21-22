#include "types.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[])
{
    struct rtcdate r;
    if (date(&r))
    {
        printf(2, "date failed\n");
        exit(0);
    }
    // Pon aqu í tu có digo para imprimir la fecha en el formato que desees
    printf(1, "%d/%d/%d\n", r.day, r.month, r.year);
    exit(0);
}
