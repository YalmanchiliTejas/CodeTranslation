#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <complex>
#include <cctype>
#include <cassert>
#include <sstream>
 
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
 
typedef long long ll;
typedef complex<double> P;
typedef complex<double> Vec;
typedef pair<int, int> pii;
typedef pair<int, pii> p;
 
#define INF (1<<29)
#define INFL (1ll<<60)
#define EPS (1e-10)
#define PI (acos(-1))
const ll MOD = 1000000007ll;

int main() {
	int n;
	string s;
	cin >> n >> s;
	
	int d[112345];
	REP(i, 2) REP(j, 2) {
		d[0] = i;
		d[1] = j;
		
		FOR(k, 2, n) d[k] = d[k - 2] ^ (d[k - 1] == 0) ^ (s[k - 1] == 'o');
		
		
		if (((d[n - 2] == d[0]) ^ d[n - 1]) == (s[n - 1] == 'o') && ((d[1] == d[n - 1]) ^ d[0]) == (s[0] == 'o')) {
			REP(k, n) putchar(d[k]?'W':'S');
			puts("");
			return 0;
		}
	}
	puts("-1");
	return 0;
}
