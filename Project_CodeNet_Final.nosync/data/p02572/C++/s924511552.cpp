#include<bits/stdc++.h>
using namespace std;
#define loop(i,x,z) for (int i=x;i<z;i++)
using ll = long long;
const ll M = 1000000007;
ll n, A[200002], s = 0;
int main()
{
	cin >> n;
	loop(i, 0, n)cin >> A[i],s+=A[i];
	s %= M;
	ll ans = 0;
	loop(i, 0, n)
	{
		s -= A[i];
		s = (s + M) % M;
		ans += A[i] * (s)%M;
		ans %= M;
	}
	cout << ans;
}