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
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

int n;
int p[200];
int invp[200];
void ope(int k) {
	Rep(i, k, n) {
		swap(p[i], p[i - k]);
	}
	rep(i, n)invp[p[i]] = i;
}
vector<int> ans;
void oper(int k) {
	ans.push_back(k); ope(k);
}
void solve() {
	cin >> n;
	rep(i, n)cin >> p[i]; rep(i, n)invp[p[i]] = i;
	rep(i,49900) {
		if (p[0]>0&&p[0] < p[n - 1])oper(n - 1);
		oper(1);
	}
	while (p[0] != 0)oper(1);
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i] << endl;
	}
	/*rep(i, n) {
		if (i > 0)cout << " ";
		cout << p[i];
	}
	cout << endl;*/
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}