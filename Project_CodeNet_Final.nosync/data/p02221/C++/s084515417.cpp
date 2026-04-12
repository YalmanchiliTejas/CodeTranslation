#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>
#include<array>


using namespace std;

#define REP(i, n) for(int i = 0;i < (n);++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), (n))
#define ub(v,n) upper_bound(v.begin(), v.end(), (n))
//#define int long long
//#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
typedef array<int, 3> arr3;
std::random_device rd;
std::mt19937 mt(rd());
constexpr int MOD = 1e9 + 7; constexpr int MAX = 200020;
const double pi = acos(-1); constexpr double EPS = 1e-8;
constexpr ll INF = 1e18;

int dp[1 << 20][20];//[i,i+2^j)の勝者
bool done[1 << 20][20];
string S;
int p[1 << 20];

int winner(int x, int y) {
	if (x > y)swap(x, y);
	if (S[y - x-1] == '1')return y;
	else return x;
}
int func(int i, int j) {
	if (done[i][j])return dp[i][j];
	if (j == 0) {
		done[i][j] = true;
		return dp[i][j] = p[i];
	}
	else {
		done[i][j] = true;
		int x = func(i, j - 1);
		int y = func(i + (1 << (j - 1)), j - 1);
		return dp[i][j] = winner(x, y);
	}
}

void solve() {
	int N; cin >> N;
	cin >> S;
	REP(i, 1 << N) {
		cin >> p[i];
		p[i + (1 << N)] = p[i];
	}
	//REP(i, 1 << N) {
	//	REP(j, N + 1) {
	//		pe(i); pe(j); print(func(i,j));
	//	}
	//}
	//print("1,2");
	//print(func(1, 2));
	REP(k, 1 << N) {
		int res = func(k, N);
		print(res);
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}
