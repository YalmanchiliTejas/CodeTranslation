#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<map<ll, ll>> V(N);

	for (ll i = 0; i < N; ++i)
	{
		string s; cin >> s;
		for (auto e : s)
		{
			++V[i][e];
		}
	}

	string res;
	auto m = V[0];

	for (auto &p : m)
	{
		char t = p.first;
		ll mi = p.second;
		for (ll i = 1; i < N; ++i)
		{
			mi = min(mi, V[i][t]);
		}
		for (ll i = 0; i < mi; ++i)
			res += t;
	}
	sort(res.begin(), res.end());
	std::cout << res << std::endl;
}