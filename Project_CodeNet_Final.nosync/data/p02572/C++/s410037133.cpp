#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ld> vld;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()

int main()
{
	fastIO;
	const int mod = 1e9 + 7;
	int n; cin >> n;
	ll ans = 0, sum = 0;
	vll a(n);
	for(int i = 0; i < n; i++) 
	{
		cin >> a[i]; 
		if(i > 0) ans += sum*a[i] % mod, ans %= mod;
		sum += a[i]; sum %= mod;
	}
	cout << ans << endl;

	return 0;
}