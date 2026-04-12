#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <fstream>
#include <array>
#include <map>
#include <queue>
#include <time.h>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <assert.h>
#include <unordered_set>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) (min(a,b) <= (x) && (x) <= max(a,b)) //hei
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007LL 
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589
 
 
#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
	std::fill((T*)array, (T*)(array + N), val);
}
 
//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define INF 10000000000000000LL
#define chmax(a,b) a = max(a,b)
#define chmin(a,b) a = min(a,b)
 
struct Edge {
	int from, to;
	ll w;
	bool operator<(const Edge& rhs) const {
		return MP(w, MP(from, to)) < MP(rhs.w, MP(rhs.from, rhs.to));
	}
 
};
typedef vector<vector<Edge>> Graph;
typedef unsigned long long ull;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll m, ll n)
{
	return m * n / gcd(m, n);
}
ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = (res * x) % MODU;
		x = (x*x)%MODU;
		n >>= 1;
	}
	return res;
}
ll divmod(ll a, ll b) { // a/b(mod m)
								  // a/b (mod m)
								  // a*b^-1
								  // b^-1 * b = 1
								  // b^(m-1) = 1 
								  // b^(m-2) * b = 1
								  // b^-1 = b^(m-2)

								  // a/b = a * b^(m-2)

	return (a * mod_pow(b, MODU - 2)) % MODU;
}


ll fmemo[10000] = {};
ll factorial(ll n) {//階乗

	if (n > 0) {
    assert(n < 10000);
if(fmemo[n] != 0) return fmemo[n];
		return fmemo[n] = (n * factorial(n - 1))%MODU;
	}
	else {
		return 1;
	}
}

  ll dp[200010][3][2] = {};
int main(){
  int n;
  cin >> n;
  vector<ll> a(n + 10);

  REP(i,n)cin >> a[i];
  Fill(dp, LLONG_MIN  / 3);

  dp[0][0][0] = 0;

  rep(i,0,n){
    REP(j, 3){
      if(dp[i][j][1] != LLONG_MIN  / 3)
        dp[i + 1][j][0] = dp[i][j][1];

      if(dp[i][j][0] != LLONG_MIN  / 3)
        dp[i + 1][j][1] = dp[i][j][0] + a[i];

      if(j){
        if(dp[i][j - 1][0] != LLONG_MIN  / 3)
          dp[i + 1][j][0] = max(dp[i][j-1][0],dp[i + 1][j][0]);
      }
    }
  }

  if(n % 2){
    cout << max(dp[n][1][0],dp[n][2][1]) << endl;
  }
  else 
    cout << max(dp[n][0][0],dp[n][1][1]) << endl;
  return 0;
} 