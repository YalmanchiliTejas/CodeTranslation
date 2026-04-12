#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
ll A[200000 + 10];

ll cnt_ox[200000 + 10], cnt_xo[200000 + 10];
ll dp_ox[200000 + 10][3];

int main() {
	for (int i = 0; i < 200000; i++) {
		for (int j = 0; j < 3; j++)
			dp_ox[i][j] = -1e18;
	}
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];

	for (int i = 0; i < N; i++) {
		cnt_ox[i + 1] = cnt_ox[i];
		cnt_xo[i + 1] = cnt_xo[i];
		if (i % 2 == 0)cnt_ox[i + 1] += A[i];
		else if (i % 2 == 1)cnt_xo[i + 1] += A[i];
	}

	ll ans = max(cnt_xo[N], cnt_ox[N]);
	//1回変化  (ox)(xo)
	for (int i = 0; i < N; i += 2) {
		ans = max(ans, cnt_ox[i] + (cnt_xo[N] - cnt_xo[i]));
	}

	//奇数限定　1回飛ばし (ox)x(xo)
	if (N % 2 == 1) {
		ll tmp = A[0];
		for (int i = 0; i < N; i++) {
			tmp = min(tmp, A[i]);
		}
		ans = max(ans, cnt_ox[N] - tmp);
	}

	//奇数限定　(xoxoxox) たぶん偶数の中で包含されてるけど
	if (N % 2 == 1) {
		ans = max(ans, cnt_xo[N]);
	}

	//奇数限定 (ox)(xo)x(xo) 2回変化
	if (N % 2 == 1) {
		dp_ox[1][0] = A[0];
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < 3; j++) {
				if (dp_ox[i][j] == -1e18)continue;
				if (j == 0) {
					//oxを継続させる。
					dp_ox[i + 2][0] = dp_ox[i][j] + A[i + 1];
					//xoへシフトする。
					dp_ox[i + 2][1] = max(dp_ox[i + 2][1], dp_ox[i][j] + A[i + 2]);
				}
				else if (j == 1) {
					//xoを継続させる。
					dp_ox[i + 2][1] = max(dp_ox[i + 2][1], dp_ox[i][j] + A[i + 2]);
					//oxへシフトする。
					dp_ox[i + 3][2] = max(dp_ox[i + 3][2], dp_ox[i][j] + A[i + 3]);
				}
				else if (j == 2) {
					//oxを継続させる。
					dp_ox[i + 2][2] = max(dp_ox[i + 2][2], dp_ox[i][j] + A[i + 2]);
				}
			}
		}
		ans = max(ans, dp_ox[N - 1][2]);
	}

	cout << ans << endl;
	return 0;
}