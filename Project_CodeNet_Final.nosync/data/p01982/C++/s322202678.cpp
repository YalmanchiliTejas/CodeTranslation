#include "bits//stdc++.h"
using namespace std;
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main() {
	int A[50];
	int n, l, r;
	while (cin >> n >> l >> r, n) {
		for (int i = 0; i < n; i++) cin >> A[i];
		int ans = 0;
		for (int i = l; i <= r; i++) {
			int idx = -1;
			for (int j = 0; j < n; j++) {
				if (i%A[j] == 0) {
					idx = j + 1;
					break;
				}
			}
			if (idx == -1) {
				if (n % 2 == 0) ans++;
			}
			else {
				if (idx % 2) ans++;
			}
		}
		cout << ans << endl;
	}
}
