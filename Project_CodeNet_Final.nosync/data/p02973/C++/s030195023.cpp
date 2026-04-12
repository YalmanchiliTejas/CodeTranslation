#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <utility>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}

template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";}
template <typename T, typename... V>void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef HOME
#warning CHECK int:ll::INT_MAX:LLONG_MAX
#define maxn 20
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define maxn 2000006
#define gcd __gcd
#define debug(x...)
#endif

#define ff first
#define endl '\n'
#define ss second
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define PI 3.14159265358979323846264338327950L
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fr(i,x,n) for(int i=x;i>=n;i--)
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

int n;
vector<int> a, col, tree;

int merge(int l, int r) {
	if (col[l] < col[r]) return l;
	return r;
}

void update(int ui, int uval, int l, int r, int ind) {
	if (l == r) {
		if (l == ui) {
			col[ui] = uval;
			tree[ind] = l;
			return;
		}
	}

	if (ui < l or r < ui) return;

	int mid((l + r) >> 1);
	if (ui <= mid) update(ui, uval, l, mid, 2 * ind);
	else update(ui, uval, mid + 1, r, 2 * ind + 1);

	tree[ind] = merge(tree[2 * ind], tree[2 * ind + 1]);
	return;
}

int query(int ql, int qr, int qval, int l, int r, int ind) {
	if (col[tree[ind]] >= qval) return -1;

	if (qr < l or r < ql) return -1;

	if (l == r) return l;

	int mid((l + r) >> 1);

	int left = query(ql, qr, qval, l, mid, 2 * ind);
	if (left != -1) return left;

	int right = query(ql, qr, qval, mid + 1, r, 2 * ind + 1);
	return right;

}

int main() {

	cin >> n;
	a.resize(n, 0); for (int i = 0; i <= n - 1; i++) cin >> a[i];
	col.resize(n, -1);
	tree.resize(4 * n + 1, 0);

	int mx = 0;

	for (int i = 0; i <= n - 1; i++) {
		int j = query(0, mx - 1, a[i], 0, n - 1, 1);

		if (j != -1) update(j, a[i], 0, n - 1, 1);
		else {
			update(mx, a[i], 0, n - 1, 1);
			mx++;
		}
	}

	cout << mx;



	return 0;
}