#include <stdio.h>
#include <string.h>

int main(void)
{
    char stn[3];
    char t[2];
    char u[2];
    char v[2];

    scanf("%s", stn);

    strncpy(t, stn, 1);
    t[1] = '\0';
    strncpy(u, stn+1, 1);
    u[1] = '\0';
    strncpy(v, stn+2, 1);
    v[1] = '\0';

    if ((t[0]==u[0])&&(t[0]==v[0])){
        printf("No");
    }else{
        printf("Yes");
    }

    return 0;
}