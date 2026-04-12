#include <iostream>
#include <string>
using namespace std;

int N;
string S;
string ans;

bool chk_anim(void) {
	bool ret = true;
	for (int i = 2; i < N; ++i) {
		if (S[i - 1] == 'o' && ans[i - 1] == 'S')
			ans[i] = (ans[i - 2] == 'S') ? 'S' : 'W';
		else if (S[i - 1] == 'o' && ans[i - 1] == 'W')
			ans[i] = (ans[i - 2] == 'S') ? 'W' : 'S';
		else if (S[i - 1] == 'x' && ans[i - 1] == 'S')
			ans[i] = (ans[i - 2] == 'S') ? 'W' : 'S';
		else if (S[i - 1] == 'x' && ans[i - 1] == 'W')
			ans[i] = (ans[i - 2] == 'S') ? 'S' : 'W';
		else {
			ret = false;
			return ret;
		}
	}

	if (S[N - 1] == 'o' && ans[N - 1] == 'S') {
		if (ans[0] != ans[N - 2])
			ret = false;
	}
	else if (S[N - 1] == 'o' && ans[N - 1] == 'W') {
		if (ans[0] == ans[N - 2])
			ret = false;
	}
	else if (S[N - 1] == 'x' && ans[N - 1] == 'S') {
		if (ans[0] == ans[N - 2])
			ret = false;
	}
	else if (S[N - 1] == 'x' && ans[N - 1] == 'W') {
		if (ans[0] != ans[N - 2])
			ret = false;
	}
	else
		ret = false;

	if (S[0] == 'o' && ans[0] == 'S') {
		if (ans[1] != ans[N - 1])
			ret = false;
	}
	else if (S[0] == 'o' && ans[0] == 'W') {
		if (ans[1] == ans[N - 1])
			ret = false;
	}
	else if (S[0] == 'x' && ans[0] == 'S') {
		if (ans[1] == ans[N - 1])
			ret = false;
	}
	else if (S[0] == 'x' && ans[0] == 'W') {
		if (ans[1] != ans[N - 1])
			ret = false;
	}
	else
		ret = false;

	return ret;
}

int main(void) {
	cin >> N;
	cin >> S;

	ans.resize(N, ' ');
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
