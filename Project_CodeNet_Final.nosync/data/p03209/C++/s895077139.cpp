#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;


ll N, X;
ll ans = 0;
ll A[51];
ll P[51];


ll a(int level) {
	if (A[level] != -1) return A[level];
	else return A[level] = 2 * a(level - 1) + 3;
}

ll p(int level) {
	if (P[level] != -1) return P[level];
	else return P[level] = 2 * p(level - 1) + 1;
}

ll dfs(ll remain, ll level) {
	//if (level == 0) return (remain <= 0) ? 0 : 1;
	if (remain == 1) return (level == 0) ? 1 : 0;
	else if (remain <= 1 + a(level - 1)) return dfs(remain - 1, level - 1);
	else if (remain == 2 + a(level - 1)) return p(level - 1) + 1;
	else if (remain <= 2 + 2 * a(level - 1)) return p(level - 1) + 1 + dfs(remain - 2 - a(level - 1), level - 1);
	else return p(level);
}

int main() {
	cin >> N >> X;

	for (int i = 0; i < 51; i++) A[i] = P[i] = -1;
	A[0] = 1;
	P[0] = 1;

	cout << dfs(X, N) << endl;

	return 0;
}