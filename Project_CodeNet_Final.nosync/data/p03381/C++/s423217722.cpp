#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b,b+n);
        int l=b[(n-1)/2],m=b[n/2];
        for(int i=0;i<n;i++)
        {
            if(a[i]<=l)
                printf("%d\n",m);
            else
                printf("%d\n",l);
        }
    }
    return 0;
}
