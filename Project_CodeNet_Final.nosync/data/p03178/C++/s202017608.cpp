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
const ll MOD=1000000007;
const ll INF=1e18;

string A;
int K;
int dp[10010][2][111];

signed main() {
    IOS();
    //(1ll<<N)シフト演算のオーバーフローに気をつける
    //MOD同士の引き算に注意
    cin>>A>>K;
    int N=A.size();
    dp[0][0][0]=1;
    rep(i,0,N){
        rep(j,0,2){
            int x=j?9:A[i]-'0';
            rep(l,0,K){
                int x=j?9:A[i]-'0';
                rep(d,0,x+1){
                    (dp[i+1][j||d<x][(l+d)%K]+=dp[i][j][l])%=MOD;
                }
            }
        }
    }
    cout<<(dp[N][0][0]+dp[N][1][0]-1+MOD)%MOD<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
