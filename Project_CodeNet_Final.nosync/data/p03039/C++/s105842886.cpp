#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
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

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MP make_pair
#define EACH(i,c) for(auto i: c)
#define SORT(c) sort((c).begin(),(c).end())

#define ALL(a)  (a).begin(),(a).end()

const int MAX = 510000;
const LL MOD = 1e9 + 7;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

LL sub(LL N, LL M, LL K)
{
	LL tmp = 0;
	int s1 = max(1LL, K - (N - 1) * M), e1 = min(M + 1, K);
	FOR(j, s1, e1){
		int s2 = max(1LL, K - (N - 2) * M - j), e2 = min(M + 1, K - j + 1);
		LL c = COM(M, j);
		FOR(k, s1, e2){
			tmp += ((c * COM(M, k)) % MOD) * ((((2 < N) ? COM((N - 2) * M, K - (j + k)) : 1) * j * k) % MOD);
			tmp %= MOD;
		}
	}
	LL tmp2 = 0;
	REP(i, N - 1){
		tmp2 += (N - 1 - i) * (i + 1);
		tmp2 %= MOD;
	}
	return tmp * tmp2;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	LL N, M, K;
	cin >> N >> M >> K;

	LL ret = 0;
	COMinit();

	ret += sub(N, M, K);
	ret %= MOD;
	ret += sub(M, N, K);
	ret %= MOD;

	cout << ret << endl;

	return 0;
}
