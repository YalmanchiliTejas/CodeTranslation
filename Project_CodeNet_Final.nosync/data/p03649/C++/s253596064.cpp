#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define F first
#define S second
#define pb push_back
#define fo(i, n) for(int i = 1; i <= n; ++i)

typedef long long ll;
typedef pair<int, int> pii;

const int N = 200200;
const int mod = 1e9 + 7;
ll n, a[N];
ll b[N];

ll ans ;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	ll l = 0, r = 50 * 1e16L + 10;
	fo(i, n)
		cin >> a[i];
	while(true)
	{
		int ok = 0;
		fo(i, n)
		{
			ll cnt = a[i] / n;
			if(cnt > 0)
				ok = 1;
			ans += cnt;
			a[i] %= n;
			for(int j = 1; j <= n; j++)
				if(j != i)
					a[j] += cnt;
		}
		if(!ok) break;
	}
	cout << ans;
	return 0;
}