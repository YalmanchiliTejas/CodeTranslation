#include <cstdio>

int n,a[1000000],b[1000000],m;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        b[n+m]=a[i];
        if(m==0) m++;
        else if(m>0) m=(-m);
        else m=-(m)+1;
    }
    if(n%2==1)
    for(int i=n-n/2;i<2*n-n/2;i++)
        printf("%d ", b[i]);
    else
    for(int i=2*n-n/2;i>=n-n/2+1;i--)
        printf("%d ", b[i]);
}
