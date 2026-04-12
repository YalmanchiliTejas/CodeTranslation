#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<pll> vpl;

#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define ZERO(a) memset(a,0,sizeof(a))

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

ll n;
ll dp[2][3010][3010];
ll a[3010];

ll rec(ll man, ll l, ll r){

  if(dp[man][l][r]!=LLINF)
    return dp[man][l][r];

  if(l>r)
    return dp[man][l][r]=0;

  if(man==0)
    return dp[man][l][r] = max(rec((man+1)%2,l+1,r)+a[l], rec((man+1)%2,l,r-1)+a[r]);
  else
    return dp[man][l][r] = min(rec((man+1)%2,l+1,r)-a[l], rec((man+1)%2,l,r-1)-a[r]);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;
  REP(i,n)cin>>a[i];
  REP(i,2)REP(j,3010)REP(k,3010)dp[i][j][k]=LLINF;

  ll ans = rec(0, 0, n-1);
  cout<<ans<<endl;

}
