#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (long long  i=a;i<n;i++)
#define sz(A) (int)(A.size())
#define all(x) (x).begin(),(x).end()
#define get(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int mod = 1e9 + 7;
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, 0, n)cin >> a[i];
	vector<ll>  sumj(n + 1, 0);
	vector<ll> sumi(n + 1, 0);
	for (int j = n - 1; j >= 1; j--) {
		sumj[j] = sumj[j + 1] + a[j];
		sumj[j] %= mod;
	}
	for (int i = n - 2; i >= 0; i--) {
		sumi[i] = sumi[i + 1] + a[i] * sumj[i + 1];
		sumi[i] %= mod;
	}
	cout << sumi[0] << endl;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T_ = 1;
	//cin >> T_;
	for (int i = 0; i < T_; i++)solve();
	return 0;
}

