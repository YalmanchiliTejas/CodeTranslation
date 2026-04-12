#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main()
{
	int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long long> asum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        asum[i + 1] = asum[i] + a[i];
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += ((a[i - 1] % MOD) * ((asum[n] - asum[i]) % MOD)) % MOD;
        ans %= MOD;
    }
    
    cout << ans << endl;
}