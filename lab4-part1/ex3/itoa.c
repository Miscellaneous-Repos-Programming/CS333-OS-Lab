// Create a character array generated by adding 1234 to PID of process
// Then print it

#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
    int pid = getpid();
    printf(1, "Process id : %d\n", pid);

    static char digits[] = "0123456789";
    char buf[16];
    pid += 1234;
    buf[15] = '\0';

    int i = 14;
    do{
        buf[i--] = digits[pid % 10];
    }while((pid /= 10) != 0);

    int len = 16 - i;
    char dest[len];
    memmove(dest, &buf[i+1], len + 1);

    i = 0;
    char c = dest[i];
    while((c = dest[i++]) != '\0') {
        printf(1, "%c\n", c);
    }
    printf(1, "%s\n", dest);
    exit();
}