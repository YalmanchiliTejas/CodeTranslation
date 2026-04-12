#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(int a = 0;a < n;a++)
#define repi(a,b,n) for(int a = b;a < n;a++)

const ull mod = 1000000007;

int main(void)
{
	ll n;
	cin >> n;
	vector<ll> vs(n);
	rep(i, n)
	{
		cin >> vs[i];
		vs[i] *= -1;
	}
	vector<ll> s;
	ll color = 0;
	rep(i, n) {
		auto item = vs[i];
		auto u = upper_bound(s.begin(), s.end(), item);
		if (u == s.end()) {
			color++;		
			s.push_back(item);
		}
		else {
			*u = item;
		}
	}
	cout << color << endl;
	return 0;
}
