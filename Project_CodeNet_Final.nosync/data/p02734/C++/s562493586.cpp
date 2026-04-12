#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAX = 3000;
const ll MOD = 998244353;

ll ways[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, s;
	cin >> n >> s;
	ways[0] = 1;
	ll ans(0);

	for (int i(0); i < n; ++i)
	{
		int val;
		cin >> val;
		for (int x(s); x > val; --x)
		{
			ways[x] += ways[x-val];
			ways[x] %= MOD;
		}
		ways[val] += i+1;
		ways[val] %= MOD;
		ans += ways[s];
		ans %= MOD;
	}
	cout << ans << endl;
}

