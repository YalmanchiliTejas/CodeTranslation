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
#define EPS 1e-100
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
ll gcd(ll x, ll y) {
	if (!y)return abs(x);
	return gcd(abs(y), abs(x % y));
}
const  int N = 2e5 + 9;
ll mem[N][5];
int n, mx;
vi v1;
ll solve(int idx, int rem) {
	if (idx >= n) {
		if (rem) return 0;
		return -1e16;
	}
	ll& ret = mem[idx][rem];
	if (ret != -1) return ret;
	ret = v1[idx];
	if (n - idx - 1 == rem)
		return ret;
	ret += solve(idx + 2, rem);
	if (rem)
		ret = max(ret, v1[idx] + solve(idx + 3, rem - 1));
	if (rem == 2)
		ret = max(ret, v1[idx] + solve(idx + 4, 0));
	return ret;
}
int main() {
//	file();
	fast();
	memset(mem, -1, sizeof mem);
	cin >> n;
	v1 = vi(n);
	for (auto& it : v1) cin >> it;
	if (n & 1) mx = 2;
	else mx = 1;
	//watch(solve(0, mx));
	ll ans = max(solve(0, mx), solve(1, mx - 1));
	if (n & 1)
		ans = max(ans, solve(2, mx - 2));
	cout << ans << endl;
	return 0;
}