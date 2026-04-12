#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

namespace
{
	ll RecL(int s, int e, vvl& dp, const vl& a)
	{
		static const ll MAX = 10000000000000000;
		if (dp[s][e] != MAX)
			return dp[s][e];
		if (s == e)
			return dp[s][e] = a[s];
		ll k = a[s] - RecL(s + 1, e, dp, a);
		ll m = a[e] - RecL(s, e - 1, dp, a);
		return dp[s][e] = max(k, m);
	}
}

void EducationalDP_L()
{
	static const ll MAX = 10000000000000000;
	int N;
	cin >> N;
	vl a(N);
	for(auto& x : a)
		cin >> x;
	vvl dp(N, vl(N, MAX));
	ll ret = RecL(0, N - 1, dp, a);
	cout << ret << endl;
}
int main()
{
	EducationalDP_L();
	return 0;
}