#include <bits/stdc++.h>
using namespace std;
#define endl            "\n"
#define ll                long long
#define all(v)            ((v).begin()), ((v).end())
#define sz(v)            ((int)((v).size()))
#define clr(v, d)        memset(v, d, sizeof(v))
#define rep(i, v)        for(int i=0;i<sz(v);++i)
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)
#define vi                vector <int>
#define vl                vector <ll>
#define ii                pair <ll,ll>
#define vii                vector <ii>
const double PI = 2 * acos(0.0);
void run() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
const ll M = 3 * 1e3, mod = 1e9 + 7;
int n;
ll dp[M + 5][M + 5][2];
vi v;
ll sol(int i, int j, bool turn) {
	if (i > j)
		return 0;
	ll &ret=dp[i][j][turn];
	if(~ret)return ret;
	if (turn) {
		return ret=max(sol(i + 1, j, !turn) + v[i], sol(i, j - 1, !turn) + v[j]);
	} else {
		return ret=min(sol(i + 1, j, !turn) - v[i], sol(i, j - 1, !turn) - v[j]);
	}
}
int main() {
	run();
	cin >> n;
	v.resize(n);
	lp(i,n)
		cin >> v[i];
	clr(dp, -1);
	cout << sol(0, n - 1, 1);
}
