#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define sqr(x) (x)*(x)
#define endl "\n"
#define mod 1000000007

ll n,a[200002],ans,start,jump;
ll dp[200002][3];

ll call(ll pos, ll taken){
    if(pos>=n) return 0;
    if(start==0 && taken==0 && pos==n-1) return 0;
    ll &ret=dp[pos][taken];
    if(ret!=-1) return ret;
    ret=-1e18;
    ret=max(ret,a[pos]+call(pos+2,taken));
    if(taken<jump) ret=max(ret,a[pos]+call(pos+3,taken+1));
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(),cout.tie();
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    if(n%2==0){
        if(n==2) cout<<max(a[0],a[1])<<endl;
        else if(n==4){
            ans=max(a[0]+a[2],a[0]+a[3]);
            ans=max(ans,a[1]+a[3]);
            cout<<ans<<endl;
        }
        else{
            ll ans=-1e18;
            for(int i=0;i<2;i++){
                jump=1-i;
                start=i;
                memset(dp,-1,sizeof dp);
                ans=max(ans,call(i,0));
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    if(n==3){
        cout<<max(a[0],max(a[1],a[2]))<<endl;
        return 0;
    }
    if(n==5){
        ans=max(max(a[0]+a[2],a[0]+a[3]),a[0]+a[4]);
        ans=max(ans,max(a[1]+a[3],a[1]+a[4]));
        ans=max(ans,a[2]+a[4]);
        cout<<ans<<endl;
        return 0;
    }
    ll ans=-1e18;
    for(int i=0;i<3;i++){
        jump=2-i;
        start=i;
        memset(dp,-1,sizeof dp);
        ans=max(ans,call(i,0));
    }
    cout<<ans<<endl;
    return 0;
}

