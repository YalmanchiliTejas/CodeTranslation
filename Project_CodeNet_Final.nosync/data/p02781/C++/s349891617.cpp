#include <bits/stdc++.h>
#include <algorithm>  
#include <unordered_set>
#include <cmath>
#define ll long long
using namespace std;

string n;

vector<int> pref;


bool isAllZero(int left, int right) {

	if (left > right) {
		return true;
	}

	ll sum = pref[right] - ((left == 0) ? 0 : pref[left - 1]);
	return sum == 0;
}

bool bad(int i, int j, int d1, int d2) {

	int nI = n[i] - '0';
	int nJ = n[j] - '0';

	return i == 0 && (d1 > nI ||
		(d1 == nI && isAllZero(i + 1, j - 1) && d2 > nJ));
}



bool bad(int i, int j, int k, int d1, int d2, int d3) {

	int nI = n[i] - '0';
	int nJ = n[j] - '0';
	int nK = n[k] - '0';

	return i == 0 && (d1 > nI ||
		(d1 == nI && isAllZero(i + 1, j - 1)
		&& (d2 > nJ || (d2 == nJ &&
			isAllZero(j + 1, k - 1) && d3 > nK))));
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	ll k;

	cin >> n >> k;

	
	int len = n.size();
	
	vector<int> digits(len);

	for (int i = 0; i < len; i++) {
		digits[i] = n[i] - '0';
	}

	pref = vector<int>(len);
	pref[0] = digits[0];

	for (int i = 1; i < len; i++) {
		pref[i] = pref[i - 1] + digits[i];
	}

	ll ans = 0;

	if (k == 1) {
		ans = (len - 1) * 9 + int(n[0] - '0');
		cout << ans << endl;
	}
	else if (k == 2) {

		ans = 0;

		for (int i = 0; i < len; i++) {

			for (int j = i + 1; j < len; j++) {

				for (int d1 = 1; d1 <= 9; d1++) {

					for (int d2 = 1; d2 <= 9; d2++) {
						ans += !bad(i, j, d1, d2);
					}
				}
			}
		}

		cout << ans << endl;
	}
	else if (k == 3) {


		ans = 0;

		for (int i = 0; i < len; i++) {

			for (int j = i + 1; j < len; j++) {

				for (int k = j + 1; k < len; k++) {

					for (int d1 = 1; d1 <= 9; d1++) {

						for (int d2 = 1; d2 <= 9; d2++) {

							for (int d3 = 1; d3 <= 9; d3++) {

								ans += !bad(i, j, k, d1, d2, d3);
							}

						}
					}
				}
			}
		}

		cout << ans << endl;


	}











	return 0;
}