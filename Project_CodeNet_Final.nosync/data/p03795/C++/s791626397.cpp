#include <cstdio>
#include <cmath>

int main()
{
    int a,b,n;
    scanf("%d",&n);
    a = n*800;
    b = (n/15) * 200;
    printf("%d\n",a - b);
}