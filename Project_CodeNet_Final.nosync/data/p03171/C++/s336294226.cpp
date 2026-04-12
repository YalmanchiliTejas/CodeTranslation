#include <bits/stdc++.h>
using namespace std;
 
#define int long long
//#define uint __int128_t

#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define low(a,b) lower_bound(all(a),(b))-(a).begin()
#define upp(a,b) upper_bound(all(a),(b))-(a).begin()
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<vint> vvint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
typedef pair<pint,pint> PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD=998244353;
const ll INF=1e18;

int N;
int a[3030];
int dp[3030][3030];

int solve(int l,int r,int turn){
    if(dp[l][r]!=-1)return dp[l][r];
    if(turn==N+1)return 0;
    int ans;
    if(turn%2){
        ans=max(solve(l+1,r,turn+1)+a[l],solve(l,r-1,turn+1)+a[r]);
    }else{
        ans=min(solve(l+1,r,turn+1)-a[l],solve(l,r-1,turn+1)-a[r]);
    }
    dp[l][r]=ans;
    return ans;
}

signed main() {
    IOS();
    //(1ll<<N)シフト演算のオーバーフローに気をつける
    cin>>N;
    rep(i,0,N){
        cin>>a[i];
    }
    rep(i,0,3030)rep(j,0,3030)dp[i][j]=-1;
    cout<<solve(0,N-1,1)<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
    return 0;
}