#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define N 3005
const int mod = 998244353;

int n, a[N], S;

ll ans = 0, f[N];

int main()
{
	scanf("%d%d", &n, &S);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)	
	{
		f[0]++;
		if(a[i] > S) continue;
		(ans += 1ll * (n - i + 1) * f[S - a[i]]) %= mod;
		for(int j = S; j >= a[i]; j--) (f[j] += f[j - a[i]]) %= mod;
	}
	cout << ans << endl;
	return 0;
}