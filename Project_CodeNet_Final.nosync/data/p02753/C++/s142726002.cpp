#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;
//max=({});
//条件式が真ならwhileの中身を回し続ける
//printf("%d\n", ans);


int g[15][15];
const int INF = 1001001001;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

//素因数分解
vector<pair<ll, int>>factorize(ll n) {
	vector<pair<ll, int>>res;
	for (ll i = 2;i * i <= n;++i) {
		if (n % i)continue;
		res.emplace_back(i, 0);
		while (n % i == 0) {
			n /= i;
			res.back().second++;
		}
	}
	if (n != 1)res.emplace_back(n, 1);
	return res;
}

int dp[1010][1010];
int bingo[3][3];
bool flag[3][3];

ll n;
ll ans = 0;

void dfs(ll x, int a, int b, int c) {
	if (x > n)return;
	if (a && b && c)ans++;
	dfs(10 * x + 3, 1, b, c);
	dfs(10 * x + 5, a, 1, c);
	dfs(10 * x + 7, a, b, 1);
}

int main() {
	string s;
	cin >> s;
	int resa = 0, resb = 0;
	rep(i, 3) {
		if (s[i] == 'A')resa++;
		else resb++;
	}
	if (resa == 0 || resb == 0)puts("No");
	else puts("Yes");
	return 0;
}
