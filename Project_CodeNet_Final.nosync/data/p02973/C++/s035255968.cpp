#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll md = 1000000007;

int main(int, char**) 
{
	int n, m = 0;
	cin >> n;
	multiset<ll> a;

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		auto it = a.lower_bound(x);
		if (it != a.begin()) {
			--it;
			a.erase(it);
		}
		a.insert(x);
	}

	cout << a.size() << endl;

	return 0;
}
