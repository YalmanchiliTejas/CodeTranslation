#include<stdio.h>
#include<iostream>
using namespace std;
int n,a[100005],j,k,i;
long long ans,s;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n/2;i++)
    {
        s=0;
        for(j=1,k=n;j<=n;j+=i,k-=i)
        {
            int aa=n-j;
            int b=aa-i;
            if(j==k||j-i==k)
                break;
            s+=a[j]+a[k];
            if(b>0)
                ans=max(ans,s);
        }
    }
    cout<<ans;
}
