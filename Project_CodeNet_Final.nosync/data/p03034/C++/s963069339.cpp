#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ll cot=0;
        int l=0;
        int r=n-1;
        while(1)
        {
            l+=i,r-=i;
            if(l==r||r<=i||l-i==r) break;
            cot+=a[l]+a[r];
            ans=max(ans,cot);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
