#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

ll patties(int l) {
	return l == 0 ? 1 : 2 * patties(l - 1) + 1;
}

ll layers(int l) {
	return l == 0 ? 1 : 2 * layers(l - 1) + 3;
}

ll patties(int l, ll i) {
	if(l == 0)
		return i == 1;
	if(i >= layers(l) - l)
		return patties(l);
	ll ans = 0;
	if(i >= layers(l - 1) + 1) {
		ans += patties(l - 1);
		if(i >= layers(l - 1) + 2) {
			ans++;
			if(i > layers(l - 1) + 2)
				ans += patties(l - 1, i - layers(l - 1) - 2);
		}
	}
	else {
		ans += patties(l - 1, i - 1);
	}
	return ans;
}

int main() {
	int N;
	ll X;
	cin >> N >> X;
	cout << patties(N, X) << endl;
}
