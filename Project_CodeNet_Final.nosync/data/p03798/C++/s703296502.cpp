#include <iostream>
#include <string>
using namespace std;

string S, ans;

int main() {
	int N;
	cin >> N >> S;
	string pattern[4] = {"SS", "SW", "WS", "WW"};
	for (auto pa : pattern) {
		ans = pa;
		for (int i = 1; i <= N-2; i++) {
			if ((ans[i] == 'S' && S[i] == 'o') || (ans[i] == 'W' && S[i] == 'x')) {
				ans += ans[i-1];
			}
			else {
				ans += ans[i-1] == 'S' ? 'W' : 'S';
			}
		}

		bool flag_first;
		if ((S[0] == 'o' && ans[0] == 'S') || (S[0] == 'x' && ans[0] == 'W')) {
			if (ans[1] == ans[N-1]) flag_first = true;
			else flag_first = false;
		}
		else if ((S[0] == 'o' && ans[0] == 'W') || (S[0] == 'x' && ans[0] == 'S')) {
			if (ans[1] != ans[N-1]) flag_first = true;
			else flag_first = false;
		}

		bool flag_last;
		if ((S[N-1] == 'o' && ans[N-1] == 'S') || (S[N-1] == 'x' && ans[N-1] == 'W')) {
			if (ans[0] == ans[N-2]) flag_last = true;
			else flag_last = false;
		}
		else if ((S[N-1] == 'o' && ans[N-1] == 'W') || (S[N-1] == 'x' && ans[N-1] == 'S')) {
			if (ans[0] != ans[N-2]) flag_last = true;
			else flag_last = false;
		}

		if (flag_first && flag_last) {
			break;
		}
		else {
			ans = "-1";
		}
	}
	cout << ans << endl;
}
