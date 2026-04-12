#include <bits/stdc++.h>

using namespace std;

int n,a[1000006];

int main()
{
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    reverse(a,a+n);

    for(int i=0; i<n; i+=2)
    {
        printf("%d ",a[i]);
    }

    for(int i=n-1; i>0; i--)
    {
        if(i%2==0) i--;
        printf("%d ",a[i]);
    }
}
