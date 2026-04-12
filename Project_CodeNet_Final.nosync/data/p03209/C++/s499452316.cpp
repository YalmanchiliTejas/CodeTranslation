#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

ll pate[110], cnt[110];
ll dfs(int level, ll eat) {
	ll ans = 0;
	if (level == 0) return 1;

	if (eat >= 1) eat--;

	if (eat != 0) {
		if (eat >= cnt[level - 1]) {
			ans += pate[level - 1];
			eat -= cnt[level - 1];
		}
		else {
			ans += dfs(level - 1, eat);
			eat = 0;
		}
	}

	if (eat >= 1) {
		ans++;
		eat--;
	}

	if (eat != 0) {
		if (eat >= cnt[level - 1]) {
			ans += pate[level - 1];
			eat -= cnt[level - 1];
		}
		else {
			ans += dfs(level - 1, eat);
			eat = 0;
		}
	}

	if (eat >= 1) eat--;
	return ans;
}

int main()
{
	ll N, X;
	cin >> N >> X;
	pate[0] = 1;
	cnt[0] = 1;
	for (int i = 1; i <= N; i++) {
		pate[i] = pate[i - 1] * 2 + 1;
		cnt[i] = cnt[i - 1] * 2 + 3;
	}
	cout << dfs(N, X) << endl;
}
