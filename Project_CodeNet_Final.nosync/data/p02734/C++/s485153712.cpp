#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 998244353

ll N,S;
vector<ll> A;
ll dp[3001][3001];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N>>S;
  A.resize(N);
  rep(i,N)cin>>A[i];

  dp[0][0]=1;
  rep(i,N)rep(j,S+1){
  	(dp[i+1][j]+=dp[i][j])%=mod;
  	if(j+A[i]<=S){
  		ll t=1;
  		if(j==0) (t*=(i+1))%=mod;
  		if(j+A[i]==S) (t*=(N-i))%=mod;
  		(dp[i+1][j+A[i]]+=dp[i][j]*t%mod)%=mod;
  	}
  }

  cout<<dp[N][S]<<endl;

  return 0;
}
