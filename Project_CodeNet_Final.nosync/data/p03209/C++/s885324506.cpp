#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> lay;
vector<ll> p;
ll n, k;

//level n ,layer x

ll fun(ll n, ll x)
{
	if (n == 0)
		return (x <= 0 ? 0 : 1);
	if (x <= lay[n - 1] + 1)
		return fun(n - 1, x - 1);
	return p[n - 1] + 1 + fun(n - 1, x - 1 - (lay[n - 1] + 1));
	
}

int main()
{
	cin >> n >> k;
	lay.push_back(1), p.push_back(1);
	for (int i = 1; i <= n; i++)
	{
		ll l = lay[i - 1] * 2 + 3;
		ll pp = p[i - 1] * 2 + 1;
		lay.push_back(l);
		p.push_back(pp);
	}
	cout << fun(n, k) << endl;
}