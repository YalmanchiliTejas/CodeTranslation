#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    char c[8];
    while(1){
        gets(c);
        int n=atoi(c);
        if( n<=0 ) break ;
        int z=1,d=5,t=1,s=3,x;
        while(n--){
            gets(c);
            switch(*c){
            case 'N': x=d;d=t;t=7-x; break ;
            case 'E': x=s;s=t;t=7-x; break ;
            case 'W': x=t;t=s;s=7-x; break ;
            case 'S': x=t;t=d;d=7-x; break ;
            case 'R': x=s;s=d;d=7-x; break ;
            case 'L': x=d;d=s;s=7-x; break ;
            }
            z+=t;
        }
        printf("%d\n",z);
    }
    return 0 ;
}