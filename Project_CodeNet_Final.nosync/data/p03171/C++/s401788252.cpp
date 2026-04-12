#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define P pair<int,int>
using namespace std;

int a[3000];
int dp[3000][3000];//x～yが残っているとき操作する方の勝ち点
int saiki(int x, int y) {
	if (x == y)return a[x];
	if (dp[x][y] != -1)return dp[x][y];
	int S = max(a[x] - saiki(x + 1, y), a[y] - saiki(x, y - 1));
	return dp[x][y] = S;
}
signed main() {
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << saiki(0, n - 1) << endl;
}