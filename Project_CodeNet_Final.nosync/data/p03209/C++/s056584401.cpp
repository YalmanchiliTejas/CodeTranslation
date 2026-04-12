#include <bits/stdc++.h>
using namespace std;

#define int long long

#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define low(a,b) lower_bound(all(a),(b))
#define upp(a,b) upper_bound(all(a),(b))
#define fill(i,n) memset(i,n,sizeof(i))
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
const ll MOD=1000000007;
const ll INF=1e18;

int N,K;
int dp[55];
int pdp[55];
int ans=0;

void dfs(int N,int K){
    if(N==-1||K==0)return;
    if(dp[N]<=K){
        ans+=pdp[N];
        K-=dp[N];
        dfs(N,K);
    }else if(dp[N-1]+2<=K){
        ans+=pdp[N-1]+1;
        K-=dp[N-1]+2;
        dfs(N-1,K);
    }else dfs(N-1,K-1);
}

signed main() {
    IOS();
    cin>>N>>K;
    pdp[0]=dp[0]=1;
    rep(i,0,50){
        pdp[i+1]=2*pdp[i]+1;
        dp[i+1]=2*dp[i]+3;
    }
    dfs(N,K);
    cout<<ans<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    




















































    return 0;
}