#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int a, int b)
{
	return (0LL + a + b) % mod;
}

inline int mult(int a, int b)
{
	return (1LL*a*b)%mod;
}

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	auto suff = a;
	for(int i = n - 2; i >= 0; i--)
		suff[i] = add(suff[i], suff[i + 1]);

	int res = 0;
	for(int i = 0; i < (n - 1); i++)
	{
		res = add(res, mult(a[i], suff[i + 1]));
	}

	cout << res << endl;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}
