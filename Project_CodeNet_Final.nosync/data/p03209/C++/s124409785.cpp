#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,n;
ll len[100],gs[100];
ll dfs(ll l,ll r,int x,ll sum,ll pos){
    if(sum==0)return 0;
    if(x==1){
        return max(0ll,min(3ll,sum+pos-1-l));
    }
    ll ans=0;
    ll mid=(l+r)/2;
    if(sum+pos-1<mid)ans+=dfs(l+1,mid-1,x-1,sum-1,l+1);
    else if(sum+pos-1==mid)ans+=gs[x-1]+1;
    else{
        ans+=gs[x-1]+1+dfs(mid+1,r-1,x-1,sum-len[x]/2-1,mid+1);
    }
    return ans;
}
int main()
{
    cin>>n>>x;
    gs[1]=3,len[1]=5;
    for(int i=2;i<=n;i++)gs[i]=gs[i-1]*2+1,len[i]=len[i-1]*2+3;
    printf("%lld\n",dfs(1,len[n],n,x,1));
}
