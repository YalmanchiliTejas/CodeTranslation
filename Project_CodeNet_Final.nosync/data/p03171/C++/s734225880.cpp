#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 29);
const ll LINF = 1e18;
const double PI = acos(-1);

template<typename T>vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }
template<typename T, typename U, typename... V>
typename enable_if<is_same<T, U>::value != 0>::type
fill_v(U& u, const V... v) { u = U(v...); }
template<typename T, typename U, typename... V>
typename enable_if<is_same<T, U>::value == 0>::type
fill_v(U& u, const V... v) { for (auto& e : u) fill_v<T>(e, v...); }
template<class T> bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T & a, const T & b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vll A(N);
	REP(i, N) {
		cin >> A[i];
	}
	bool isTaro = (N % 2 == 1);
	auto dp = make_v<ll>(N, N);
	REP(cnt, N) {
		REP(l, N) {
			int r = l + cnt;
			if (r >= N)break;
			if (cnt == 0) {
				if (isTaro) {
					dp[l][r] = A[l];
				}
				else {
					dp[l][r] = -A[l];
				}
			}
			else {
				if (isTaro) {
					dp[l][r] = max(dp[l][r - 1]+ A[r], dp[l + 1][r]+ A[l]);
				}
				else {
					dp[l][r] = min(dp[l][r - 1] - A[r], dp[l + 1][r] - A[l]);
				}
			}
		}
		isTaro = !isTaro;
	}
	cout << dp[0][N - 1] << endl;
	return 0;
}
