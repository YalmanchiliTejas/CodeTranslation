#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
#define endl "\n"
using namespace std;
const ll N=500010;

const ll inf=N*1000000000;

vector<ll> ar;
ll dp[N][3][2];
int vis[N][3][2];

ll func(ll idx,ll two,ll three)
{
    if(idx==-1){
        if(two==0&&three==0){return -inf;}
        return 0;
    }
    if(idx<0){
        return -inf;
    }
    if(idx==0){
        if(two==0&&three==0){return -inf;}
        return ar[0];
    }
    if(vis[idx][two][three]==0){
        ll ans=-inf;
        ans=max(ans,ar[idx]+func(idx-2,two,three));
        if(three==0){
            if(two==0){
                ans=max(ans,ar[idx]+func(idx-4,two,1));
                ans=max(ans,ar[idx]+func(idx-3,1,0));
            }
            else if(two==1){
                ans=max(ans,ar[idx]+func(idx-3,2,0));
            }
        }
        dp[idx][two][three]=ans;
        vis[idx][two][three]=1;
    }
    return dp[idx][two][three];
}




ll even()
{
    ll n=ar.size();

    ll pre[n],suf[n];
    for(ll i=0;i<n;++i){
        if(i<=1){
            pre[i]=ar[i];
        }
        else{
            pre[i]=ar[i]+pre[i-2];
        }
    }
    for(ll i=n-1;i>=0;--i){
        if(i>=n-2){
            suf[i]=ar[i];
        }
        else{
            suf[i]=ar[i]+suf[i+2];
        }
    }
    ll ans=max(pre[n-1],pre[n-2]);
    for(ll i=0;i<n;++i){
        if(i%2==0){continue;}
        if(i+2<n)
        {ans=max(ans,pre[i-1]+suf[i+2]);}
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    ar.resize(n);
    for(ll i=0;i<n;++i){cin>>ar[i];}
    if(n%2==0){
        cout<<even();
    }
    else{
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        ll ans=func(n-1,0,0);
        ar.pop_back();
        ans=max(ans,even());
        ar.pop_back();
        ll sum=0;
        for(ll i=0;i<ar.size();++i){
            if(i%2==0){sum+=ar[i];}
        }
        ans=max(ans,sum);
        cout<<ans;
    }

    return (0);
}
