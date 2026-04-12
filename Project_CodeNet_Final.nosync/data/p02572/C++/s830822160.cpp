/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int MOD = 1000000007;
const int MOD1 = 998244353;
const int maxn = 100010;
const int lim = (int)1e9;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	vector<lli> a(n);
	for (auto &i : a)
		cin >> i;
	lli sum = accumulate(a.begin(), a.end(), 0ll);
	vector<lli> pre(n, 0ll);
	pre[0] = a[0];
	for (int i = 1; i < n; ++i)
		pre[i] = pre[i - 1] + a[i];
	lli res = 0ll;
	for (int i = 0; i + 1 < n; ++i)
		res = (res + (1ll * a[i] * ((sum - pre[i]) % MOD))) % MOD;
	if (res < 0ll)
		res += MOD;
	cout << res << endl;
}