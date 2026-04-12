#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const ll modinvtwo = 5e8 + 4;

ll power(int n, int m)
{
	ll p = 1;
	for(int i = 0; i < m; i++)	p *= n;
	return p;
}

int main()
{
	int n;	cin >> n;
	vector<ll> v(n);

	ll sump = 0, sumsq = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		sump = (sump + v[i]) % mod;
		sumsq = (sumsq + (v[i]*v[i]) % mod) % mod;
	}
	sump = (sump * sump) % mod;
	ll sum = ((sump < sumsq ? (sump - sumsq) + mod : sump - sumsq) * modinvtwo) % mod;

	cout << sum  << endl;
}