#include <stdio.h>
int main()
{
    int a,b,c;//定义a,b,c三个变量（各位大佬也可以用short,long,long long等）
    scanf("%d %d %d",&a,&b,&c);//读入
    if((b*10+c)%4==0) printf("YES");//判断：只要末两位可以被4整除，它本身就可以被4整除
        else printf("NO");//否则就不被4整除
}