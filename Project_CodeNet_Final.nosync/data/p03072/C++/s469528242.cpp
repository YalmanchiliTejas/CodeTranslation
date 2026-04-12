#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> h;

int main(int, char**)
{
	ll n, ans = 0;
	cin >> n;
	h.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> h[i];
		int j;
		for (j = 0; j < i; ++j) {
			if (h[j] > h[i])
				break;
		}
		if (i == j) ++ans;
	}

	cout << ans << endl;

	return 0;
}
