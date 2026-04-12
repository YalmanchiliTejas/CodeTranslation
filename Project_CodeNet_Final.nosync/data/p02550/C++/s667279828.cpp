#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;

void solve()
{
	ll int n, x, m;
	cin >> n >> x >> m;
	ll a = x;
	int done[100001] = {0};
	vector<int> prog;
	int c = 1;
	ll ans = 0;
	for (; c <= n; c++)
	{
		if (done[a] != 0)
			break;
		done[a] = c;
		prog.push_back(a);
		ans += a;
		a = (a * a) % m;
	}
	ll ans1 = 0;
	for (int c1 = done[a] - 1; c1 < prog.size(); c1++)
		ans1 += prog[c1];
	ans += ans1 * ((n - c + 1) / (prog.size() - done[a] + 1));
	for (int c1 = done[a] - 1, i = 0; i < (n - c + 1) % (prog.size() - done[a] + 1); c1++, i++)
		ans += prog[c1];
	cout << ans << endl;
}
int main()
{

	int t;
	t = 1;
	for (int c = 0; c < t; c++)
		solve();
}