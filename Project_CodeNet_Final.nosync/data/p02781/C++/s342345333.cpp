#include <iostream>
#include <string>
using namespace std;

string S;
int K;
int sz;

int select_free(void) {
	int cnt = 0;
	if (K == 1)
		cnt = (sz - 1) * 9;
	else if (K == 2)
		cnt = (sz - 1) * (sz - 2) / 2 * (9 * 9);
	else
		cnt = (sz - 1) * (sz - 2) * (sz - 3) / 6 * (9 * 9 * 9);
	return cnt;
}

int check_upper(void) {
	int m = sz;
	for (int i = 1; i < sz; ++i) {
		if (S[i] != '0') {
			m = i;
			break;
		}
	}
	return m;
}

bool check_upper2(int x, int y) {
	for (int i = x + 1; i < y; ++i) {
		if (S[i] != '0')
			return true;
	}
	return false;
}

int select_large(void) {
	int cnt = 0;
	if (K == 1)
		cnt = (int)(S[0] - '0');
	if (K == 2) {
		cnt = ((int)(S[0] - '0') - 1) * (sz - 1) * 9;
		int nxt = check_upper();
		for (int i = 1; i < sz; ++i) {
			if (nxt < i)
				cnt += 9;
			else if (nxt == i)
				cnt += (int)(S[i] - '0');
		}
	}
	if (K == 3) {
		cnt = ((int)(S[0] - '0') - 1) * (sz - 1) * (sz - 2) / 2 * 9 * 9;
		int nxt = check_upper();
		for (int i = 1; i < sz - 1; ++i) {
			for (int j = i + 1; j < sz; ++j) {
				if (nxt < i)
					cnt += 9 * 9;
				else if (nxt == i) {
					if (check_upper2(i, j))
						cnt += (int)(S[i] - '0') * 9;
					else {
						if (S[i] != '0') {
							cnt += ((int)(S[i] - '0') - 1) * 9;
							cnt += (int)(S[j] - '0');
						}
						else
							cnt += (int)(S[j] - '0');
					}
				}
			}
		}
	}
	return cnt;
}

int solve(void) {
	int cnt_1 = select_free();
	int cnt_2 = select_large();
	int cnt = cnt_1 + cnt_2;
	return cnt;
}

int main(void) {
	cin >> S >> K;
	sz = S.length();
	int ans = 0;
	if (sz >= K)
		ans = solve();
	cout << ans << '\n';
	return 0;
}
