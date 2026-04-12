#pragma warning(disable:4996)
#include "bits/stdc++.h"
using namespace std;

//macro
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,a,b) for(int i=(int)(b) - 1;i>=(int)(a);i--)
#define rrep(i,n) RREP(i,0,n)
#define each(i, ctn) for (auto &&i : (ctn))
#define all(a) (a).begin(),(a).end()
#define mp make_pair
#define INF 114514810
#define INFL 1145148100000000000LL
#define EPS (1e-8)
#define MOD 1000000007
#define PI 3.141592653589793
#define equals(a,b)(fabs((a)-(b))<EPS)

//alias
using ll = long long;
using ull = unsigned long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vs = vector<string>;
using P = pair<ll, ll>;
template<class T> using heap = priority_queue<T>;
template<class T> using minheap = priority_queue<T, vector<T>, greater<T>>;

//func
template<typename A, typename T>void assign2d(A&arr, ll H, ll W, T t) { arr.resize(H);	rep(i, H) arr[i].assign(W, t); }
template<class T> ostream &operator<<(ostream &os, const vector<T> &v) { int n = v.size(); rep(i, n)os << v[i] << (i == n - 1 ? "\n" : " "); return os; }
template <class T = int> inline T in() { T x; cin >> x; return x; }
template<class T> inline void print(const T &x) { cout << x << '\n'; }
struct pre_ { pre_() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(12); } } pre__;



int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	int ans = 1;
	for (; ans < 1000000; ++ans) {
		int W = Z * (ans + 1) + Y * ans;
		if (W > X)break;
	}
	print(ans-1);
	return 0;
}