#include"bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define FOR(k,m,n) for(ll (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<< #str << " " str<<endl

constexpr int INF = (1 << 30);
constexpr ll INFL = (1ll << 60);
constexpr ll MOD = 1000000007;// 10^9+7


int N;
vector<ll> a;
vector<vector<ll>> dp;

ll dfs(int l, int r)
{
    if(dp[l][r]!=INFL) return dp[l][r];
    ll resl = dfs(l+1, r);
    ll resr = dfs(l,r-1);
    return dp[l][r] = (r-l) % 2 != N % 2
      ? max(resl + a[l], resr + a[r])
      : min(resl - a[l], resr - a[r]);
}


int main()
{
    cin>>N;
    a.resize(N);
    REP(i,N)cin>>a[i];
 
    dp.resize(N,vector<ll>(N, INFL));
    REP(i,N)dp[i][i]=a[i] * (N%2==0?-1:1);

    cout << dfs(0,N-1) << endl;
    return 0;
}
