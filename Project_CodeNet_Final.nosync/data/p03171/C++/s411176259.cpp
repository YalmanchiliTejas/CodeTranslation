#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define fi first
#define se second
#define pub push_back
#define pi pair<int,int>
#define all(v) (v).begin(), (v).end()
#define rep(i, l, r) for(int i=(int)(l);i<(int)(r);i++)
#define repd(i, l, r) for (int i=(int)(l);i>=(int)(r);i--)
#define clrg(i, l, r) for(int i=(int)(l);i<(int)(r);i++)vis[i]=0,v[i].clear();
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int powermod(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
#define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<" ";}cout<< endl;}}
#define clr(a,x) memset(a,x,sizeof(a))
#define rr(v) for(auto &val:v)
#define print(v) for (const auto itr : v){cout<<itr<<' ';}cout<<"\n";
#define ln length()
#define sz size()
#define mod 1000000007
#define elif else if
int n; vector<int> v;
int dp[3002][3002][2];
int solve(int l,int r,int p){
   if(l==r)return v[l];
   if(dp[l][r][p%2]!=-1e18)return dp[l][r][p%2];
   int ans=-1e18;
   ans=max(ans,v[l]-solve(l+1,r,p+1));
   ans=max(ans,v[r]-solve(l,r-1,p+1));
   dp[l][r][p%2]=ans;
   //cout<<ans<<"\n";
   return ans;
}
int32_t main(){
   cin>>n;
   rep(i,0,n+1)rep(j,0,n+1)dp[i][j][0]=-1e18,dp[i][j][1]=-1e18;
   rep(i,0,n){
      int t; cin>>t;
      v.pub(t);
   }
   cout<<solve(0,n-1,0)<<"\n";
   return 0;
}
/*
Edge cases? n=1? a[i]<=0?
long vs int? 1LL? 64bits?
Re-read problem. Is it as easy as it seems?
KEEP CORRECTING AND SUBMITTING!
*/
