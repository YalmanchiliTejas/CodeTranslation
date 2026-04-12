#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
ll iti[12345678], test[12345678], cost[4321][4321];
signed main() {
	ll n, m, sum = 0, ans = 0; cin >> n;
	ll mae = 0, ato = n - 1;
	for(int h = 0; h < n; h++) {
		cin >> test[h];
	}
	sort(test, test + n);
	ll a = 0, cnt1 = 0, cnt2 = 0;
	while (true) {
		a++;
		if (mae == 0) { cnt1 = test[mae]; cnt2 = test[mae]; mae++; continue; }
		if (mae > ato) { break; }
		if (mae == ato) {
			sum += max(abs(test[mae] - cnt1), abs(test[mae] - cnt2));
			break;
		}
		if (a % 2 == 0) { 
			sum += abs(test[ato] - cnt1); cnt1 = test[ato]; ato--;
			sum += abs(test[ato] - cnt2); cnt2 = test[ato]; ato--;
		}
		else {
			sum += abs(test[mae] - cnt1); cnt1 = test[mae]; mae++;
			sum += abs(test[mae] - cnt2); cnt2 = test[mae]; mae++;
		}
		//cout << ' ' << sum << endl;
	}
	a = 0; cnt1 = 0; cnt2 = 0; mae = 0; ato = n - 1; ans = sum; sum = 0;
	while (true) {
		a++;
		if (ato == n - 1) { cnt1 = test[ato]; cnt2 = test[ato]; ato--; continue; }
		if (mae > ato) { break; }
		if (mae == ato) {
			sum += max(abs(test[mae] - cnt1), abs(test[mae] - cnt2));
			break;
		}
		if (a % 2 == 1) {
			sum += abs(test[ato] - cnt1); cnt1 = test[ato]; ato--;
			sum += abs(test[ato] - cnt2); cnt2 = test[ato]; ato--;
		}
		else {
			sum += abs(test[mae] - cnt1); cnt1 = test[mae]; mae++;
			sum += abs(test[mae] - cnt2); cnt2 = test[mae]; mae++;
		}
		//cout << ' ' << sum << endl;
	}
	//cout << ans << ' ' << sum << endl;
	cout << max(ans, sum) << endl;
	cin >> n; return 0;
}