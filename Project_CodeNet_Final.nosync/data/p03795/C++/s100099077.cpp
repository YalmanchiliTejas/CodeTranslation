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
	cin >> n;
	cout << n * 800 - 200 * (n / 15) << endl;
	return 0;
}
