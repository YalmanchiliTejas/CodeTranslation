#include<cstdio>
using namespace std; 
int main()
{
    int a,b,n;
    scanf("%d%d%d\n",&n,&a,&b);
    printf("%d\n",(n-b)/(a+b));
    return 0;
}