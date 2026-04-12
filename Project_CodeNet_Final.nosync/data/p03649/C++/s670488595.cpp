#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <complex>
#include <cstring>
#include <cassert>
#include <bitset>

using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i > (b); i--)
#define forIt(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forRev(it, a) for(__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define ft(a) __typeof((a).begin())
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define bitcount(n) __builtin_popcountll(n)
#define randchar() ((rand() % 26) + 'a')


typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int N = 200000 + 7;
const int M = 1000000;
const ll MM = 1ll * M * M;
const int inf = 1e9 + 7;
const long long linf = 1ll * inf * inf;
const double pi = acos(-1);
const double eps = 1e-7;
const bool multipleTest = 0;

ll lo = 0, hi = 10000000000000000ll + 1000;
int n;
ll a[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	
	
	ll res = 0;
	
	while (true) {
		sort(a, a + n);
//		for (int i = 0; i < n; ++i) cout << a[i] << ' '; puts("");
		int i = n - 1;
		while (i > 0 && a[i] - a[i - 1] <= n + 1) --i;
		if (i == 0) break;
		ll x = (a[i] - a[i - 1] - n - 1 + n) / (n + 1);
		int k = n - i;
		for (int j = 0; j < i; ++j) a[j] += x * k;
		for (int j = i; j < n; ++j) a[j] += x * (-n + k - 1);
		res += x * k;
//		if (a[i] - a[i - 1] <= n + 1) {
//			
//		}
	}
	
	if (a[0] >= n) {
		res += n * (a[0] - n);
		ll d = a[0] - n;
		for (int i = 0; i < n; ++i) a[i] -= d;
	}
	while (true) {
		sort(a, a + n);
		
//		for (int i = 0; i < n; ++i) cout << a[i] << ' '; puts("");
		if (a[n - 1] < n) break;
		a[n - 1] -= n;
		for (int i = 0; i + 1 < n; ++i) a[i]++;
		++res;
	}
	cout << res;
	
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin);
	//	freopen("out.txt", "w", stdout);
#endif
	int Test = 1;
	if (multipleTest)
		cin >> Test;
	for(int i = 0; i < Test; ++i) {
		solve();
	}
	
#ifdef _LOCAL_
	cout<<"\n" << 1.0 * clock() / CLOCKS_PER_SEC<<endl;
#endif
}