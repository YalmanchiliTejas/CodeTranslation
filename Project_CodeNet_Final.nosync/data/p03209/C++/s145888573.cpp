#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>
#include <future>
#define int long long
#define endre getchar();getchar();return 0
#define INF 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define input() for(int i=0;i<n;i++)cin>>a[i];
#define P pair<int,int>
#define prique priority_queue<int,vector<int>,greater<int>>
using namespace std;
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return (y, x%y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int kai(int n) {
	if (n == 0)return 1;
	return (kai(n - 1)*n) % INF;
}
int mod_pow(int x, int y, int mod) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x%mod;
		}
		x = x * x%mod;
		y >>= 1;
	}
	return res;
}
int mystoi(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		cnt += (int)(s[i] - '0') * pow(10, s.size() - i - 1);
	}
	return cnt;
}
int n, x, cnt[55], pa[55];
int solve(int a,int b) {
	if (a == 0)return 1;
	else if (b == 1)return 0;
	else if (b <= (cnt[a] - 3) / 2 + 1)return solve(a - 1, b - 1);
	else if (b == 2 + cnt[a - 1])return 1 + pa[a - 1];
	else if (b <= cnt[a] - 1)return pa[a - 1] + 1 + solve(a - 1, b - 2 - cnt[a - 1]);
	else return pa[a];
}
signed main() {
	cin >> n >> x;
	cnt[0] = 1, pa[0] = 1;
	for (int i = 1; i <= 50; i++) {
		cnt[i] = cnt[i - 1] * 2 + 3;
		pa[i] = pa[i - 1] * 2 + 1;
	}
	cout << solve(n, x) << endl;
	endre;
}