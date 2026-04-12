#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 1e9+7;
const int MAX_N = 200005;
ll A[MAX_N];

int main()
{
	int N;
	cin >> N;
	ll sum = 0;
	rep(i,N)
	{
		cin >> A[i];
		sum = (sum + A[i]) % MOD;
	}
	ll ans = 0;
	rep(i,N-1)
	{
		sum = (sum + MOD - A[i]) % MOD;
		ans = (ans + A[i] * sum) % MOD;
	}
	cout << ans << endl;
	return 0;
}