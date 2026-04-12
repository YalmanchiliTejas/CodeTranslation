#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;

int main() {
	ll n, x;
	cin >> n >> x;

	vector<ll> cnt_layer(n + 1);
	vector<ll> cnt_pat(n + 1);
	cnt_layer[0] = 1;
	cnt_pat[0] = 1;
	for (int i = 1; i <= n;i++) {
		cnt_layer[i] = cnt_layer[i - 1] * 2 + 3;
		cnt_pat[i] = cnt_pat[i - 1] * 2 + 1;
	}

	ll sum = 0;
	if (cnt_layer[n] == x) {
		sum = cnt_pat[n];
	}
	else {
		int l = n - 1;
		while (x != 0) {
			x--;
			if (cnt_layer[l] <= x) {
				sum += cnt_pat[l];
				x -= cnt_layer[l];
				if (x > 0) {
					x--;
					sum++;
				}
			}



			if (cnt_layer[l] == x) {
				x = 0;
				sum += cnt_pat[l];
			}
			l--;

		}
	}

	cout << sum << endl;
}
