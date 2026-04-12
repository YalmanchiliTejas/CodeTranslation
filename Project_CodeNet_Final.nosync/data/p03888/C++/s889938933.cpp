#include<stdio.h>

int main(void){
    int a,b;
    scanf("%d%d",&a,&b);
    int s=a*b;
    int w=a+b;
    double ans=(double)s/w;
    printf("%.10lf\n",ans);
    return 0;
}