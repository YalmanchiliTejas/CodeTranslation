#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;

	vector<ll> A(n), B;

	for (auto& a: A)
		cin >> a;

	for (auto i = A.rbegin(); i != A.rend(); i++)
	{
		auto a = (*i);
		auto j = upper_bound(B.begin(), B.end(), a);
		if (j == B.end())
			B.push_back(a);
		else
			(*j) = a;
	}

	cout << B.size() << endl;

	return 0;
}