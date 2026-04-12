#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <stack>
#include <functional>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

vector<ll> p = { 1 }, b = { 1 };

ll solve(ll n, ll x) {
	if (n == 0)return x <= 0 ? 0 : 1;
	else if (x <= 1 + b[n - 1]) return solve(n - 1, x - 1);
	else return p[n - 1] + 1 + solve(n - 1, x - 2 - b[n - 1]);
}

int main() {
	ll n, x;
	cin >> n >> x;

	for (ll i = 1; i <= n; i++)
	{
		p.push_back(2 * p[i - 1] + 1);
		b.push_back(2 * b[i - 1] + 3);
	}

	cout << solve(n, x) << endl;

}