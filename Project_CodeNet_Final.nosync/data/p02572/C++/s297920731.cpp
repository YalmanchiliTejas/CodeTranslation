#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = " << x << endl;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F;
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const double EPS = 1e-10;
const ll mod = 1e9 + 7;

const int maxn = 2e5 + 10;

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

ll a[maxn];
ll suff[maxn];

int main()
{
	ios::sync_with_stdio(false);
	int test = 1;
	while(test--)
	{
		int n;
		cin >> n;
		for(int i = 1; i <= n ; i++)
			cin >> a[i];

		for(int i = n ; i >= 1; i--)
			suff[i] = (suff[i + 1] + a[i]) % mod;
		
		ll ans = 0;
		for(int i = 1 ; i < n ; i++)
		{
			ans += (a[i] * suff[i + 1]) % mod;
			ans %= mod;
		}

		cout << ans << endl;
		
	}
	
	return 0;
}