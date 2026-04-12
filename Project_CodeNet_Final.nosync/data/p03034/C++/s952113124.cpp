#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,a[N];
int main()
{
    ll ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        ll res=0;
        int l=0,r=n-1;
        while(true)
        {
            l+=i;r-=i;
            if(l==r||l-i==r||r<=i) break;
            res+=a[l]+a[r];
            ans=max(ans,res);
        }
    }
    printf("%lld\n",ans);
}
