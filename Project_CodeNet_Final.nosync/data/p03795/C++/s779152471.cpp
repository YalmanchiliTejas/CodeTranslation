#include<stdbool.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
typedef long long ll;
using namespace std;

int main(void) {
	int n;
	cin >> n;
	cout << 800 * n - 200 * (n / 15) << endl;
	/*ll n, m, ans = 0;
	cin >> n >> m;
	if (n == m) {
		if (n == 1) {
			cout << ans << endl;
		}
		else {
			while (m >= 2) {
				ans++;
				m -= 2;
			}
			cout << ans << endl;
		}
	}
	else {
		if (n > m) {
			if (m == 1) {
				cout << ans << endl;
			}
			else {
				while (m >= 2) {
					ans++;
					m -= 2;
				}
				cout << ans << endl;
			}
		}
		else {
			while (true) {
				n--;
				m -= 2;
				ans++;
				if (m < 2) {
					cout << ans << endl;
					return 0;
				}
				if (n == 0)break;
			}
			while (m >= 4) {
				m -= 4;
				ans++;
			}
			cout << ans << endl;
		}
	}*/
	return 0;
}