#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_map>
//#include"testlib.h"
#define endl "\n"
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define RT(s) return cout<<s,0
#define watch(x) cout << (#x)<<" = "<<x<<endl
#define sz(s)    (int)(s.size())
#define PI acos(-1)
#define EPS 1e-8
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("street.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
void fast() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
}
const int N = 3e3 + 9;
int mem[N][N], n, s, mod = 998244353;
vi v1;
int solve(int idx, int sum) {
	if (sum > s) return 0;
	if (idx == n) return 0;
	int& ret = mem[idx][sum];
	if (ret != -1) return ret;
	ret = solve(idx + 1, sum);
	ll ch = solve(idx + 1, sum + v1[idx]);
	if (sum + v1[idx] == s)
		ch = n - idx;
	ret += ch;
	ret %= mod;
	return ret;
}
int main() {
	//file();
	fast();
	memset(mem, -1, sizeof mem);
	cin >> n >> s;
	v1 = vi(n);
	for (auto& it : v1) cin >> it;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += solve(i, 0);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}