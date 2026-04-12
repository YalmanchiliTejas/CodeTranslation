#include <bits/stdc++.h>
using namespace std;
#define mp(a, b) make_pair(a, b)
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
int main()
{
	int n;
	ll cur, sum = 0, tmp = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%lld", &cur);
		sum += cur * tmp % mod; sum %= mod;
		tmp += cur; tmp %= mod;
	}
	cout << sum << endl;
		
	return 0;
}