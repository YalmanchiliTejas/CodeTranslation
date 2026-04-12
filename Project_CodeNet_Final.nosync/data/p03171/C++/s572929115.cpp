#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int,int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int,int>;
using vMii = vector<Mii>;

#define fi first
#define se second
#define INF INT_MAX
#define mod(a,m) (a%m+m)%m
#define PB push_back
#define MP make_pair

int n;
vi a;
vvll memo;

ll dp(int i, int j) {
	ll& ans = memo[i][j];
	if(ans != -1) return ans;
	if(i == j) return ans = a[i];
	return ans = max(a[i] - dp(i+1, j), a[j] - dp(i, j-1));
}

int main(){
//	cout.setf(ios::fixed);
//	cout.precision(4);
	while (cin >> n) {
		a = vi(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		memo = vvll(n, vll(n, -1));
		cout << dp(0, n-1) << '\n';
	}
}

