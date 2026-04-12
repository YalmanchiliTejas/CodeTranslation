#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-3;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int n; ll a[3000];
bool chked[3000][3000];
ll ans[3000][3000];
ll dfs(int le, int ri) {
	if (ri < le)return 0;
	if (chked[le][ri])return ans[le][ri];
	chked[le][ri] = true;
	ll res = 0;
	int id = (n - (ri-le+1)) % 2;
	if (id == 0) {
		ll sle = a[le] + dfs(le + 1, ri);
		ll sri = a[ri] + dfs(le, ri - 1);
		res = max(sle, sri);
	}
	if (id == 1) {
		ll sle = -a[le] + dfs(le + 1, ri);
		ll sri = -a[ri] + dfs(le, ri - 1);
		res = min(sle, sri);
	}
	return ans[le][ri] = res;
}
int main() {
	cin >> n;
	rep(i, n)cin >> a[i];
	cout << dfs(0, n - 1) << endl;
	//stop
	return 0;
}