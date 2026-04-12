#include <iostream>
#include <array>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

using ll = long long int;

ll arr[200010] = {};

ll k = 0, res = 0;

bool check() {
	for (int i = 0; i < k; i++) {
		if (arr[i] >= k) return true;
	}
	return false;
}

int main(void) {

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	//k*k = 50*50 * 100000;
	for(ll l = 0; l <= k; l++)
	for (ll i = 0; i < k ; i++) {

		ll t = (arr[i]*k / (k+1))/k;
		res += t;
		arr[i] -= t*(k+1);

		if (t != 0) {

			for (ll j = 0; j < k; j++)
				arr[j] += (t);

			if (t > k) {
				res += (t - k)*k;

				for (ll j = 0; j < k; j++)
					arr[j] -= (t-k);
			}

		}

		/*
		for (int l = 0; l < k; l++) {
			cout << arr[l] << (l == k - 1 ? '\n' : ' ');
		}
		cout << res << endl;
		*/

	}

	while (check()) {
		res++;
		int tmp = 0;
		for (int i = 0; i < k; i++) {
			if (arr[tmp] < arr[i]) tmp = i;
		}
		for (int i = 0; i < k; i++) {
			arr[i]++;
		}
		arr[tmp] -= k+1;

	}
	/*
	for (int i = 0; i < k; i++) {
		cout << arr[i] << (i == k-1 ? '\n' : ' ');
	}*/
	
	cout << res << endl;


}


//
//int main(void) {
//
//	ll k = 0;
//
//	cin >> k;
//
//	for (int i = 0; i < 50; i++) {
//		arr[i] += 49;
//		arr[i] += k / 50;
//	}
//
//	for (ll i = 0; i < k%50; i++) {
//		arr[i%50] += 51;
//
//		for (ll j = 0; j < 50; j++) {
//			arr[j] -= 1;
//		}
//	}
//
//	cout << 50 << endl;
//
//	for (int i = 0; i < 50; i++) {
//		cout << arr[i] << (i == 49?'\n' : ' ');
//	}
//
//
//}
