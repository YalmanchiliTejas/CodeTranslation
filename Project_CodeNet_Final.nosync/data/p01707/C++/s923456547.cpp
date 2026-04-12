//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

LL N, D, X;
LL dp[2010][2010];
LL inv_[2010];

LL powm(LL x, LL y){
  if(y == 0) return 1;
  return powm(x*x%MOD, y/2) * (y%2?x:1) % MOD;
}

LL inv(LL x){
  if(inv_[x] >= 0) return inv_[x];
  return inv_[x] = powm(x, MOD-2);
}

LL C(LL x, LL y){
  LL res = 1;
  for(LL i=0;i<y;++i){
	res = res * ((x-i) % MOD) % MOD;
	res = res * inv(y-i) % MOD;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  fill(inv_, inv_+2010, -1);

  while(cin>>N>>D>>X,N){
	fill((LL*)dp, (LL*)dp+2010*2010, 0);
	
	dp[0][0] = 1;
	for(int d=0;d<N;++d){
	  for(int x=d;x<N;++x){
		dp[d+1][x+1] = (dp[d+1][x] + dp[d][x]) % MOD;
		if(x+1 >= X)
		  dp[d+1][x+1] = (dp[d+1][x+1] - dp[d][x+1-X]+MOD) % MOD;
	  }
	}
	LL ans = 0;
	for(int d=1;d<=min(N,D);++d){
	  ans += dp[d][N] * C(D,d) % MOD;
	  ans %= MOD;
	}
	cout << ans << endl;
  }

  return 0;
}