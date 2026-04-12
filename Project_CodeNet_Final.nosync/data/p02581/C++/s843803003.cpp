#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
int dp[2000][2000];
int dp1[2000];
int dp2[2000];
int dp3;
map<pair<int,int>,int> a;
void g(int x, int y, int z) {
	if (z < 0) return;
	if (z <= dp[x][y]) return;
	auto it = a.find({x,y});
	if (it != a.end() && z <= it->second) return;
	a[{x,y}] = z;
}
void f1(int x, int y, int z) {
	g(x, y, dp[z][z]+1);
	g(x, y, dp3);
	for (int i = 0; i < N; ++ i) {
		g(x, i, dp1[i]);
		g(x, i, dp2[i]);
	}
}
void f2(int x, int y) {
	for (int i = 0; i < N; ++ i) {
		g(x, i, dp[i][y]+1);
		g(x, i, dp[y][i]+1);
	}
}
int main() {
	cin >> N;
	vector<int> A(3*N);
	for (auto& x : A) { cin >> x; -- x; }
	for (int i = 0; i < N; ++ i) {
		dp1[i] = dp2[i] = -100;
		for (int j = 0; j < N; ++ j) {
			dp[i][j] = -100;
		}
	}
	dp[A[0]][A[1]] = dp1[A[0]] = dp2[A[1]] = dp3 = 0;
	int res = 0;
	for (int t = 0; t < N-1; ++ t) {
		int x = A[3*t+2];
		int y = A[3*t+3];
		int z = A[3*t+4];
		if (x == y && y == z && z == x) {
			++ res;
		} else {
			f1(x,y,z);
			f1(y,z,x);
			f1(z,x,y);
			if (x == y) f2(z, x);
			if (y == z) f2(x, y);
			if (z == x) f2(y, z);
			for (auto p : a) {
				int x = p.first.first;
				int y = p.first.second;
				int z = p.second;
				dp[x][y] = z;
				dp1[x] = max(dp1[x], z);
				dp2[y] = max(dp2[y], z);
				dp3 = max(dp3, z);
			}
			a.clear();
		}
	}
	{
		int x = A[3*N-1];
		res += max(dp3, dp[x][x]+1);
	}
	cout << res << endl;
}
