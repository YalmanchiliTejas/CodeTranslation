#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
#include<unordered_set>
using namespace std;
//int p = 998244353;
int p = 1000000007;
#define vel vector<int>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<int,pin>
#define V vector
#define Endl endl
#define veb vector<bool>
#define rev(s) reverse(s.begin(),s.end())
int max_kai = 150000;
vel kai(max_kai, 1);
vel inv_kai;
int rui(int a, int n) {
	if (n == 0) { return 1; }
	int x = rui(a, n / 2);
	x *= x; x %= p;
	if (n % 2 == 1) { x *= a; x %= p; }
	return x;
}
int inv(int a) { return rui(a, p - 2); }
void make_kai() {
	for (int i = 1; i < max_kai; i++) { kai[i] = kai[i - 1] * i; kai[i] %= p; }
	inv_kai = kai;
	rep(i, max_kai) { inv_kai[i] = inv(kai[i]); }
}
int nCr(int n, int r) {
	int a = kai[n] * inv_kai[r]; a %= p;
	a *= inv_kai[n - r]; a %= p;
	return a;
}
vel pa;
int root(int x) {
	if (pa[x] == -1) { return x; }
	int ans = root(pa[x]); pa[x] = ans;
	return ans;
}
void marge(int x, int y) {
	x = root(x);
	y = root(y);
	if (x != y) {pa[x] = y;}
}
#define lower(h,val) lower_bound(h.begin(),h.end(),val)-h.begin()
#define upper(h,val) upper_bound(h.begin(),h.end(),val)-h.begin()
int num_lp(int a, vel &nex) {
	unordered_set<int> se;
	int ans = 0;
	while (true) {
		if (se.find(a) != se.end()) {
			break;
		}
		se.insert(a);
		a = nex[a];
		ans++;
	}
	return ans;
}
int find_cr(int a, vel &nex) {
	unordered_set<int> se;
	while (true) {
		if (se.find(a) != se.end()) {break;}
		se.insert(a);
		a = nex[a];
	}
	return num_lp(a, nex);
}
int inf = 2000000000;
vvel dp;
int solve(vvel &sum, int i, int j, bool is_f) {
	int h = sum.size(); h--;
	int w = sum[0].size();
	if (i == h || j == w) { return 0; }
	if (dp[i][j] == inf) {
		int ans1 = solve(sum, i + 1, j, !is_f);
		int ans2 = solve(sum, i, j + 1, !is_f);
		ans2 += sum[i][j];
		if (is_f) {
			dp[i][j] = min(ans1, ans2);
		}
		else {
			dp[i][j] = max(ans1, ans2);
		}
	}
	return dp[i][j];
}
int rui10(int a) {
	if (a == 0) { return 1; }
	return 10 * rui10(a - 1);
}
int gcd(int a, int b) {
	if (a < b) { swap(a, b); }
	if (b == 0) { return a; }
	return gcd(b, a%b);
}
signed main(){
	int n; cin >> n;
	vel t(n);
	rep(i, n) { cin >> t[i]; }
	sor(t);
	vel x;
	int ma = t[n - 1];
	for (int i = 1; i <= ma; i++) {
		if (ma%i == 0) {
			x.push_back(i);
		}
	}
	int ans = 0;
	rep(i, n) {
		int mn = ma;
		for (auto a : x) {
			if (t[i] <= a) {
				mmin(mn, a - t[i]);
			}
		}
		ans += mn;
	}
	cout << ans << endl;
	return 0;
}
