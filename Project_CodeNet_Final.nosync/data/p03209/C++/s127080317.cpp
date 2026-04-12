
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#ifndef __MACRO_H__
#define __MACRO_H__

#define all(collection) (collection).begin(), (collection).end()  // begin to end
#define rep(i, begin, end) for (ll i = begin; i < end; i++)       // repeat
#define repr(i, begin, end) for (ll i = begin; end < i; i--)      // repeat reverse
#define size(collection) ((ll) (collection).size())               // collection size

#endif

vector<ull> lmax(50);
vector<ull> pmax(50);

void Solve(ll lv, ll& x, ll& ans)
{
	if (lv == 0)
	{
		x--;
		ans++;
		return;
	}

	x--;
	if (x <= 0)
		return;

	if (x <= lmax[lv - 1])
	{
		Solve(lv - 1, x, ans);
		return;
	}

	x -= lmax[lv - 1];
	ans += pmax[lv - 1];
	if (x <= 0)
		return;

	x--; ans++;
	if (x <= 0)
		return;

	if (x <= lmax[lv - 1])
	{
		Solve(lv - 1, x, ans);
		return;
	}

	x -= lmax[lv - 1];
	ans += pmax[lv - 1];
	if (x <= 0)
		return;

	x--;
}

int main(void)
{
	ll n, x; cin >> n >> x;

	lmax[0] = pmax[0] = 1;
	rep(i, 1, 50)
	{
		lmax[i] = lmax[i - 1] * 2 + 3;
		pmax[i] = pmax[i - 1] * 2 + 1;
	}

	ll ans = 0;
	Solve(n, x, ans);

	cout << ans;
	return 0;
}
