#include<cstdio>
int num,ans=0;
int main()
{
    scanf("%d",&num);
    ans=ans*10+num;
    scanf("%d",&num);
    ans=ans*10+num;
    scanf("%d",&num);
    ans=ans*10+num;
    ans%4?printf("NO"):printf("YES");
}