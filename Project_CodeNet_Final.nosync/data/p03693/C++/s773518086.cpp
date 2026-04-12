#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int ans = a*100+b*10+c;
    printf("%s\n",!(ans%4)?"YES":"NO");



    return 0;
}
