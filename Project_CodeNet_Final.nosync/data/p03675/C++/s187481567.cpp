#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = (1LL << 31) - 1;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1
#define MAX_N 100100 * 3

int a[1000100];
vector<int> b[2];

int main() {
	int n;
	cin >> n;
	REP(i, n)cin >> a[i];
	REP(i, n) {
		b[i % 2].push_back(a[i]);
	}
	if (n % 2 == 0) {
		REP(i, b[1].size()) {
			if (i == 0)cout << b[1][b[1].size() - 1 - i];
			else cout << " " << b[1][b[1].size() - 1 - i];
		}
		REP(i, b[0].size()) {
			cout << " " << b[0][i];
		}
		cout << endl;
	}
	else {
		REP(i, b[0].size()) {
			if (i == 0)cout << b[0][b[0].size() - 1 - i];
			else cout << " " << b[0][b[0].size() - 1 - i];
		}
		REP(i, b[1].size()) {
			cout << " " << b[1][i];
		}
		cout << endl;
	}
}