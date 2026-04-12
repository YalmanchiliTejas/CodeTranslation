#include<stdio.h>
int main()
{
    int N,f,s,t,final;
    scanf("%d",&N);
    f=N*800;
    s=N/15;
    t=s*200;
    final=f-t;
    printf("%d\n",final);
    return 0;
}
