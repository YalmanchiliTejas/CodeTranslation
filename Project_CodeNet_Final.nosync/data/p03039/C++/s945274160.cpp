#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
using namespace std;
#define vel vector<long long>
#define vvel vector<vel>
#define int long long
#define rep(i,n) for(long long i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define V vector
long long p = 1000000007;
vel kai(200001, 1);
vel ink(200001, 1);
int le = (1 << 20) + 1;
vel BIT(le, 0);
vel uni(vel &list) {
	if (list.size() == 0) { return list; }
	sort(list.begin(), list.end());
	vel ql(1, list[0]);
	rep(i, list.size() - 1) {
		if (list[i] != list[i + 1]) { ql.push_back(list[i + 1]); }
	}
	list = ql;
	return ql;
}
int ru(int a, int r) {
	if (r == 0) { return 1; }
	int ans = ru(a, r / 2);
	ans *= ans; ans %= p;
	if (r % 2 == 1) { ans *= a; }
	return ans % p;
}
int inv(int a) {
	return ru(a, p - 2);
}
void make_kai() {
	rep(i, 200000) { kai[i + 1] = (kai[i] * (i + 1)) % p; }
	rep(i, 200001) { ink[i] = inv(kai[i]); }
}
int com(int n, int r) {
	int ans = kai[n] * ink[r];
	ans %= p; ans *= ink[n - r]; ans %= p;
	return ans;
}
int per(int n, int r) {
	int ans = kai[n] * ink[n-r];
	ans %= p;
	return ans;
}
signed main() {
	make_kai();
	int n, m, k; cin >> n >> m >> k;
	int ans = 0;
	int sum_x = 0;
	for (int i = 1; i < m; i++) {
		sum_x += 2 * i*(m - i);
		sum_x %= p;
	}
	sum_x *= (n*n) % p; sum_x %= p;
	int sum_y = 0;
	for (int i = 1; i < n; i++) {
		sum_y += 2 * i*(n - i);
		sum_y %= p;
	}
	sum_y *= (m*m) % p; sum_y %= p;
	ans = sum_x + sum_y;
	ans *= com(k, 2); ans %= p;
	ans *= per(n*m, k); ans %= p;
	ans *= inv(n*m); ans %= p;
	ans *= inv(n*m - 1); ans %= p;
	ans *= ink[k]; ans %= p;
	cout << ans << endl;
	return 0;
}
