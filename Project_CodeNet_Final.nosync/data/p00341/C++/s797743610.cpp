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
#define int long long
#define vel vector<long long>
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
int inf = 6000000000000;
vel dijk(vvel &way, vel &cost, int s) {
	int n = way.size(); int m = 7 * n;
	vel ans(m, inf);
	priority_queue<pin, vector<pin>, greater<pin>> que;//cost,pla
	que.push(mkp(0,s));
	while (!que.empty()) {
		pin x = que.top(); que.pop();
		int pla = x.second;
		if (ans[pla] == inf) {
			int sum_cost = x.first;
			ans[pla] = sum_cost;
			int nex_cost = sum_cost + cost[pla];
			int mod = nex_cost % 7;
			for (auto x : way[pla/7]) {
				que.push(mkp(nex_cost, x * 7 + mod));
			}
		}
	}
	return ans;
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
int sol(int a, int b, int c, int d) {
	return abs(a*c - b * d);
}
signed main(){
	vel ans(101, 0);
	rep(i, 12) {
		int e; cin >> e;
		ans[e]++;
	}
	rep(i, 101) {
		if (ans[i] % 4 != 0) { cout << "no" << endl; return 0; }
	}
	cout << "yes" << endl;
	return 0;
}
