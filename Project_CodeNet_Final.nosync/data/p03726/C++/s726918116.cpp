#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n, x, y;
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x,int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
inline bool dfs(int x,int f = 0) {
	int cnt = 0;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != f) {
		cnt += dfs(way[i].to, x);
	}
	if(cnt >= 2) cout << "First" << '\n', exit(0);
	return ! cnt;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n - 1) {
		cin >> x >> y;
		link(x, y);
	}
	cout << (dfs(1) ? "First" : "Second") << '\n';
}
