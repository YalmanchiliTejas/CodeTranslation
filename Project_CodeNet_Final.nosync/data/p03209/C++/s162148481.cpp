#include<iostream>

using namespace std;

typedef long long ll;

int N;
ll X;

ll patty[51];
ll bread[51];

ll ans = 0;

void setup() {
	patty[0] = 1, bread[0] = 0;
	for (int i = 1; i <= 50; i++) {
		patty[i] = 1 + patty[i - 1] * 2;
		bread[i] = bread[i - 1] * 2 + 2;
	}
}

void dfs(int level, ll pos) {

	if (pos == patty[level] + bread[level]) {
		ans += patty[level];
		return;
	}
	else if (pos < patty[level] + bread[level] && pos > 2LL + patty[level - 1] + bread[level - 1]) {
		ans += 1LL + patty[level - 1];
		dfs(level - 1, pos - 2LL - patty[level - 1] - bread[level - 1]);
	}
	else if (pos == 2 + patty[level - 1] + bread[level - 1]) {
		ans += 1LL + patty[level - 1];
		return;
	}
	else if (pos > 1LL && pos < 2 + patty[level - 1] + bread[level - 1]) {
		dfs(level - 1, pos - 1LL);
		return;
	}
	else if(pos == 1){
		return;
	}
}

int main() {

	setup();

	cin >> N >> X;

	dfs(N, X);

	cout << ans << endl;

	return 0;
}