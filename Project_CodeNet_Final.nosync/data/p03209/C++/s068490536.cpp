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

ll all[60], paty[60];
void set() {
	all[0] = 1;
	paty[0] = 1;
	for (int i = 1; i <= 50; i++) {
		all[i] = all[i - 1] * 2 + 3;
		paty[i] = paty[i - 1] * 2 + 1;
	}
}
ll dfs(ll eat, ll level) {
	ll ans = 0;
	if (level == 0) return 1;
	if (eat >= 1) {
		eat--;
	}
	if (eat >= 1) {
		if (eat >= all[level - 1]) {
			ans += paty[level - 1];
			eat -= all[level - 1];
		}
		else {
			ans += dfs(eat, level - 1);
			eat = 0;
		}
	}
	if (eat >= 1) {
		ans++;
		eat--;
	}
	if (eat >= 1) {
		if (eat >= all[level - 1]) {
			ans += paty[level - 1];
			eat -= all[level - 1];
		}
		else {
			ans += dfs(eat, level - 1);
			eat = 0;
		}
	}
	if (eat >= 1) {
		eat--;
	}
	return ans;
}
int main()
{
	int N;
	ll X;
	cin >> N >> X;
	set();
	cout << dfs(X, N) << endl;
}