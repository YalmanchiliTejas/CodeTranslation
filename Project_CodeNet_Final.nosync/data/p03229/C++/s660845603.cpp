#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, j, n) for (int i = j; i < (n); ++i);
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// Tenka1 Programmer Beginner Contest-C, 1111, 
	int n; cin >> n;
	vector<ll> v(n);
	rep(i, n) cin >> v[i];
	sort(v.begin(), v.end());
	int left, right;
	ll ans = 0;
	vector<ll> ansvec(n);
	if (n % 2 == 0) {
		left = v[n / 2 - 1];
		right = v[n / 2];
		ansvec[0] = left;
		ansvec.back() = right;
		v.erase(find(v.begin(), v.end(), left));
		v.erase(find(v.begin(), v.end(), right));
		if (v.size() == 0) {
			ans = abs(left - right);
			cout << ans << endl;
			return 0;
		}
		for (int i = 1; i < n - 1; i += 2) {
			ansvec[i] = v[n - 2 - 1 - i / 2];
		}
		for (int i = 1; i < n - 1; i += 2) {
			ansvec[n - 1 - i] = v[i / 2];
		}
	}
	else {
		left = v[n / 2];
		if (abs(left - v[n / 2 - 1]) < abs(left - v[n / 2 + 1])) {
			right = v[n / 2 - 1];
			ansvec[0] = left;
			ansvec.back() = right;
			v.erase(find(v.begin(), v.end(), left));
			v.erase(find(v.begin(), v.end(), right));
			for (int i = 1; i < n - 1; i += 2) {
				ansvec[n - 1 - i] = v[n - 2 - 1 - i / 2];
			}
			for (int i = 2; i < n - 1; i += 2) {
				ansvec[i] = v[i / 2 - 1];
			}
		}
		else {
			right = v[n / 2 + 1];
			ansvec[0] = left;
			ansvec.back() = right;
			v.erase(find(v.begin(), v.end(), left));
			v.erase(find(v.begin(), v.end(), right));
			for (int i = 1; i < n - 1; i += 2) {
				ansvec[i] = v[i / 2];
			}
			for (int i = 2; i < n - 1; i += 2) {
				ansvec[n - 1 - i] = v[n - 2 - 1 - i / 2 + 1];
			}
		}
	}
	rep(i, n - 1) {
		ans += abs(ansvec[i] - ansvec[i + 1]);
	}
	cout << ans << endl;
	return 0;
}