#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <array>
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


int main() {

	long long n, x, m; cin >> n >> x >> m;
	map<long long, long long> ind;

	vector<long long> v;
	v.push_back(0);
	ind[0] = 0;
	v.push_back(x);
	ind[x] = 1;
	long long st = -1;

	while (true) {
		long long nxt = ((v.back() % m) * (v.back() % m)) % m;
		if (ind.find(nxt) != ind.end()) {
			debug(nxt);
			st = ind[nxt];
			break;
		}

		ind[nxt] = v.size();
		v.push_back(nxt);
	}
	debug(v.size());
	debug(v);

	debug(st);
	for (long long i = 1; i < v.size(); i++) v[i] += v[i - 1];

	if (st == 0) {
		if (n >= v.size()) cout << v.back();
		else cout << v[n];

		return 0;
	}

	long long pre = v[st - 1];

	long long sze = (long long)v.size() - st;
	long long nn = n - (st - 1);
	long long mid = (nn / sze) * (v.back() - v[st - 1]);
	long long post = 0;
	if (nn % sze > 0) {
		post += v[(nn % sze) + st - 1] - v[st - 1];
	}
	debug(pre, nn / sze, v.back(), v[st - 1], post);
	cout << pre + mid + post;

	return 0;
}