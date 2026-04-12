#include<iostream>
#include<string>
int N;
int ans[100010];
std::string s;
bool solve(int a,int b) {
	ans[0] = a;
	ans[1] = b;
	for (int i = 1; i < N; i++) {
		if (s[i] == 'o') {
			if (ans[i] == 1)ans[i + 1] = ans[i - 1];
			else ans[i + 1] = -ans[i - 1];
		}
		else {
			if (ans[i] == -1)ans[i + 1] = ans[i - 1];
			else ans[i + 1] = -ans[i - 1];
		}
	}
	if (ans[0] != ans[N])return false;
	if (s[0] == 'o') {
		if (ans[0] == 1)return ans[1] == ans[N - 1];
		if (ans[0] == -1)return ans[1] != ans[N - 1];
	}
	if (s[0] == 'x') {
		if (ans[0] == 1)return ans[1] != ans[N - 1];
		if (ans[0] == -1)return ans[1] == ans[N - 1];
	}
}

void out() {
	for (int i = 0; i < N; i++) {
		std::cout << (ans[i] == 1 ? 'S' : 'W');
	}
	std::cout << std::endl;
}
int main() {
	std::cin >> N >> s;
	if (solve(1, 1)) {
		out();
		return 0;
	}
	if (solve(-1, 1)) {
		out();
		return 0;
	}
	if (solve(1, -1)) {
		out();
		return 0;
	}
	if (solve(-1, -1)) {
		out();
		return 0;
	}
	std::cout << -1 << std::endl;
	return 0;
}