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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[3003],dp[3003][3003][2];
int sol(int l,int r,int f){
    if(l>r) return 0;
    if(dp[l][r][f]!=-1) return dp[l][r][f];
    int &ans=dp[l][r][f];
    if(f==0) return ans=max(sol(l+1,r,!f)+a[l],sol(l,r-1,!f)+a[r]);
    else return ans=min(sol(l+1,r,!f)-a[l],sol(l,r-1,!f)-a[r]);
}
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<sol(1,n,0)<<endl;
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