#include <bits/stdc++.h>

#define F first
#define S second
#define pii pair<int, int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 110, mod = 1e9 + 7;

ll h[N], dp[N][N], f[N][N], y[N], t[N];

int power(int a, int b)
{
	if(b == 0) return 1;
	ll res = power(a, b/2); 
	res *= res, res %= mod;
	if(b & 1) res *= a, res %= mod;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector <int> vc; vc.pb(0);

	int n; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> h[i];
		vc.pb(h[i]);
	}

	sort(vc.begin(), vc.end());
	vc.resize(unique(vc.begin(), vc.end()) - vc.begin());
	
	int cnt = 0;
	for (auto Y : vc)
		y[cnt ++] = Y;

	for (int i=0; i<n; i++)
		t[i] = lower_bound(vc.begin(), vc.end(), h[i]) - vc.begin();


	for (int j=0; j<t[0]; j++)
	{
		int y1 = y[j], y2 = y[j + 1];
		if(y2 >= y1 + 2)
		{
			int R = h[0] - y[j] - 2, L = h[0] - y[j + 1];
			dp[0][j] = power(2, R + 1) + mod - power(2, L); dp[0][j] %= mod;
		}
		int pw = max(0LL, h[0] - y[j + 1] - 1);
		f[0][j] = power(2, pw);
	}

	for (int i=1; i<n; i++)
		for (int j=0; j<t[i]; j++)
		{
			if (j < t[i] - 1)
			{
				if(j + 1 <= t[i - 1])
				{
					ll way = dp[i - 1][j];
					if(h[i] > h[i - 1]) way *= power(2, h[i] - h[i - 1]);
					dp[i][j] = way % mod;

					bool done = 0;

					way = f[i - 1][j];
					if(j == t[i - 1] - 1) way *= 2, way %= mod, done = 1;

					if(h[i] > h[i - 1]) way *= power(2, h[i] - h[i - 1] - done), way %= mod;
					f[i][j] = way;

				}else
				{
					ll way = 2LL * f[i - 1][t[i - 1] - 1] % mod;
					int R = h[i] - y[j] - 2, L = h[i] - y[j + 1];
					way *= (power(2, R + 1) + mod - power(2, L)) % mod;
					dp[i][j] = way % mod;

					f[i][j] = 2LL * f[i - 1][t[i - 1] - 1] % mod;
					f[i][j] *= power(2, h[i] - y[j + 1] - 1); f[i][j] %= mod;
				}
			}else
			{
				if(t[i - 1] >= j + 1){
					dp[i][j] = dp[i - 1][j];
					ll ps = 0;
					for (int k=j; k<t[i - 1]; k++)
					{
						ps += 2LL * f[i - 1][k]; ps %= mod;
						if(k + 1 < t[i - 1]) ps += 2LL * dp[i - 1][k + 1], ps %= mod;
					}
					f[i][j] = ps;
				}else
				{
					ll way = 2LL * f[i - 1][t[i - 1] - 1];
					way *= power(2, h[i] - y[j] - 1) + mod - 1; way %= mod;
					dp[i][j] = way;

					f[i][j] = 2LL * f[i - 1][t[i - 1] - 1] % mod;
				}
			}
		}

	ll ans = 0;
	for(int j=0; j<t[n - 1]; j++) {
		ans += (2LL * dp[n - 1][j]) % mod;
		ans += (2LL * f[n - 1][j]) % mod;
		ans %= mod;
	}

	ans %= mod;
	cout << ans << endl;

}
