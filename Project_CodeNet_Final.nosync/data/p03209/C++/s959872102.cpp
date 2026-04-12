#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll cntP[55],cnt[55];

ll f(ll n, ll x)
{
	if (x == 0) return ll(0);
	if (n == 0) return ll(1);
	ll res = 0;
	if (x <= 1+cnt[n-1])
	{
		return f(n-1,x-1);
	}
	else
	{
		return cntP[n-1] + 1 + f(n-1,x-(2+cnt[n-1]));
	}
}

int main()
{
	ll N,X;
	cin >> N >> X;
	cntP[0] = 1;
	cnt[0] = 1;
	rep(i,N)
	{
		cntP[i+1] = cntP[i]*2 + 1;
		cnt[i+1] = cnt[i]*2 + 3;
	}
	cout << f(N,X) << endl;
	return 0;
}