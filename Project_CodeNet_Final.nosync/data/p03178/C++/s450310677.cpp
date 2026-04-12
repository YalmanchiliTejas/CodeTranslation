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

const int MOD = 1e9 + 7;

int modul(int a, int m) {
	return (a + 10*m) % m;
}

int main(){
//	cout.setf(ios::fixed);
//	cout.precision(4);
	string k;
	int d;
	while (cin >> k >> d) {
		int n = k.size();
		vvvll dp(n, vvll(d, vll(2, 0)));
		for (int i = 0; i < k[0] - '0'; ++i) {
			dp[0][modul(i, d)][0]++;
		}
		dp[0][modul(k[0] - '0', d)][1] = 1;
		for (int i = 1; i < n; ++i) {
		//	cerr << "i: " << i << endl;
			for (int j = 0; j < d; ++j) {
		//		cerr << "j: " << j << endl;
				for (int l = 0; l < 10; ++l) {
		//			cerr << "l: " << l << endl;
					dp[i][j][0] = (dp[i][j][0] + dp[i-1][modul(j - l, d)][0]) % MOD;
					if(l < k[i] - '0') 	{
						dp[i][j][0] = (dp[i][j][0] + dp[i-1][modul(j - l, d)][1]) % MOD;
					}
					else if (l == k[i] - '0') {
						dp[i][j][1] = (dp[i][j][1] + dp[i-1][modul(j - l, d)][1]) % MOD;
					}
				}
			}
		}
		ll ans = (dp[n-1][0][0] + dp[n-1][0][1]) % MOD;
		ans = (ans - 1 + MOD) % MOD;
		cout << ans << '\n';
	}
}


