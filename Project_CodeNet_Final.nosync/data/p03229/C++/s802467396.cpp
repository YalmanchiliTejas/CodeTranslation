
// C - Align

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int A[100000];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	sort(A, A+N);

	int L = A[0];
	int R = A[0];
	int l = 1;
	int r = N-1;

	ll ans = 0;

	while(l <= r) {
		int max_dif;
		int max_dif_case;

		max_dif = abs(L - A[l]);
		max_dif_case = 1;

		if (abs(L - A[r]) > max_dif) {
			max_dif = abs(L - A[r]);
			max_dif_case = 2;
		}

		if (abs(R - A[l]) > max_dif) {
			max_dif = abs(R - A[l]);
			max_dif_case = 3;
		}

		if (abs(R - A[r]) > max_dif) {
			max_dif = abs(R - A[r]);
			max_dif_case = 4;
		}

		switch (max_dif_case) {
			case 1:
				ans += abs(L - A[l]);
				L = A[l];
				l++;
				break;

			case 2:
				ans += abs(L - A[r]);
				L = A[r];
				r--;
				break;

			case 3:
				ans += abs(R - A[l]);
				R = A[l];
				l++;
				break;

			case 4:
				ans += abs(R - A[r]);
				R = A[r];
				r--;
				break;
		}
	}

	cout << ans << endl;

	return 0;
}