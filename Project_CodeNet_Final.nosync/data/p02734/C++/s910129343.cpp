#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,s,a[3003],dp[3003][3003];
int get(int pos,int rem){
    if(rem==0) return (n-pos+1);
    if(pos==n) return 0;
    int &ans=dp[pos][rem];
    if(ans!=-1) return ans;
    ans=get(pos+1,rem);
    if(rem>=a[pos]) ans=(ans+get(pos+1,rem-a[pos]))%hell;
    return ans;
}
void solve(){
    int ans=0;
    memset(dp,-1,sizeof dp);
    cin>>n>>s;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) ans=(ans+get(i,s))%hell;
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}