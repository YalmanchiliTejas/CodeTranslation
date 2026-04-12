#include <iostream>
#include <string>
using namespace std;

int N;
string S;
string ans;

bool chk_anim(void) {
	for (int i = 2; i <= N + 1; ++i) {
		char ox = (i < N + 1) ? S[i - 1] : S[0];
		if ((ox == 'o' && ans[i - 1] == 'S') || (ox == 'x' && ans[i - 1] == 'W'))
			ans[i] = ans[i - 2];
		else
			ans[i] = (ans[i - 2] == 'S') ? 'W' : 'S';
	}

	if (ans[N] == ans[0] && ans[N + 1] == ans[1]) {
		ans.erase(N);
		return true;
	}
	else
		return false;
}

int main(void) {
	cin >> N;
	cin >> S;

	ans.resize(N + 2, ' ');
	ans[0] = 'S';	ans[1] = 'S';
	bool flag = chk_anim();
	if (!flag) {
		ans[0] = 'S';	ans[1] = 'W';
		flag = chk_anim();
	}
	if (!flag) {
		ans[0] = 'W';	ans[1] = 'S';
		flag = chk_anim();
	}
	if (!flag) {
		ans[0] = 'W';	ans[1] = 'W';
		flag = chk_anim();
	}

	if (flag)
		cout << ans << '\n';
	else
		cout << "-1" << '\n';
	return 0;
}
