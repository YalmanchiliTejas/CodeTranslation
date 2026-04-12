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
typedef long long  ll;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

ll lcd(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}

//左側と右側の累積和
vector<ll> le[1 << 17], ri[1 << 17];
void solve() {
	int n;
	cin >> n;
	vector<ll> s(n);
	rep(i, n)cin >> s[i];
	rep1(i, n - 1) {
		ll d = (n - 1) / i;
		le[i].resize(d+1);
		ri[i].resize(d + 1);
		rep(j, d) {
			le[i][j + 1] = le[i][j] + s[i*j];
			ri[i][j + 1] = ri[i][j] + s[n - 1 - i * j];
		}
	}
	ll ans = -INF;
	rep1(i, n-1) {

		for (int j = 0; j <= n - 1; j+= i) {
			int a = n - 1 - j;
			if (a <= 1)continue;
			int b = a - i;
			if (b <= 0||b>=a)continue;
			if (b%i == 0) {
				ll d = b / i; d++;
				if (d*i + b < n - 1)continue;
			}
			ll sum = 0;
			ll l = (n - 1 - b - 1) / i;
			sum += le[i][l + 1];
			ll r = (n - 1 - a) / i + 1;
			sum += ri[i][r];
			//cout << a<<" " << b << " "<<sum<<endl;
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}
