#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<array>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cassert>
#include<functional>
#include<random>
#include<complex>
#include<bitset>
#include<chrono>
//#include<boost/multiprecision/cpp_int.hpp>
#define int int64_t
#define uint uint64_t
#define REP(i, a, b) for (int64_t i = (int64_t)(a); i < (int64_t)(b); i++)
#define rep(i, a) REP(i, 0, a)
#define SZ(X) ((int64_t)((X).size()))
#define ITR(x, a) for (auto x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define HAS(a, x) (a.find(x) != a.end())
#define Min(x) *min_element(ALL(x))
#define Max(x) *max_element(ALL(x))
#define Unique(L) (L.erase(unique(ALL(L)), L.end()))
#define intmax (std::numeric_limits<int64_t>::max() / 4)
#define doublemax (std::numeric_limits<double>::max() / 4)
using namespace std;
//typedef boost::multiprecision::cpp_int bigint;
const double EPS = 1e-9;
const double PI = acos(-1.0);




signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<array<int, 2>>a(N), b(N);
	rep(i, N) {
		cin >> a[i][0] >> a[i][1];
		if (a[i][1] < a[i][0])swap(a[i][0], a[i][1]);
		b[i][0] = a[i][1];
		b[i][1] = a[i][0];
	}
	sort(ALL(a));
	sort(ALL(b));

	//大きいやつと小さいやつに分ける
	int ans = (a[N - 1][0] - a[0][0])*(b[N - 1][0] - b[0][0]);

	//広いやつと狭いやつに分ける
	int r = a[N-1][0], l = intmax;
	rep(i,N-1) {

		//l,rは狭いやつの範囲
		l = min(a[i][1], l);
		r = max(r, a[i][1]);
		ans = min(ans, (b[N-1][0] - a[0][0]) * (r - min(l, a[i + 1][0])));
	}
	cout << ans << endl;

	return 0;
}