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
#include <cmath>
#include <climits>

using namespace std;
typedef long long ll;

int main() {
	ll N;
	cin >> N;
	vector<ll> h(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> h[i];
	}

	ll ans = 0, max = 0;
	for (ll i = 0; i < N; i++)
	{
		if (h[i] >= max)
		{
			ans++;
			max = h[i];
		}
	}
	cout << ans << endl;
}