#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define ll long long
#define vel vector<ll>
#define vvel vector<vel>
#define vvvel vector<vvel>
#define veb vector<bool>
#define pin pair<ll,ll>
#define mkp make_pair
#define mot pair<D,D>//time,dist
#define path pair<ll,int>//cost,to
#define int long long
using namespace std;
vvel ta_min(0);
vvel ta_max(0);
int leth = 1024 * 512;
int p = 1000000007;
vel par;
vel dis;
int n;
void mmax(ll &a, ll b) { a = max(a, b); }
void mmin(ll &a, ll b) { a = min(a, b); }
pin root(int ser) {
	if (par[ser] == -1) {return mkp(ser,0);}
	pin x=root(par[ser]);
	x.second += dis[ser];
	par[ser] = x.first;
	dis[ser] = x.second;
	return x;
}
void uni(int a, int b,int d) {
	pin p1 = root(a);
	pin p2 = root(b);
	int a1 = p1.first;
	int b1 = p2.first;
	if (a1 != b1) {
		par[b1] = a1;
		dis[b1] = d + dis[a] - dis[b];
	}
}
bool issame(int x, int y) {
	return root(x).first == root(y).first;
}
void ref(int &x) { x = x % p; x = (x + p) % p; }
int rui(int a, int n) {
	if (n == 0) { return 1; }
	int x = rui(a, n / 2);//return a^n%p
	x *= x; ref(x);
	if (n % 2 == 1) { x *= a; }
	ref(x);
	return x;
}
void nim(int x, int k) {
	while (1) {
		int x; int k; cin >> x >> k;
		vel gr(x + 1);
		gr[0] = 0;
		for (int i = 1; i <= x; i++) {
			vel ko(x + 1, 0);
			for (int j = 1; j <= i / k; j++) { ko[gr[i - j]]++; }
			int ind = 0;
			while (ko[ind] != 0) { ind++; }
			gr[i] = ind;
		}
		for (int i = 1; i <= x; i++) { cout << gr[i] << " "; }
	}
}
signed main() {
	int n, k; cin >> n >> k;
	int ans = 0;
	for (int b = k + 1; b <= n; b++) {
		int qn = n - k; if (k == 0) { qn--; }
		ans += (qn / b)*(b - k);
		int re = qn % b;
		ans += min(re + 1, b - k);
	}
	cout << ans << endl;
	return 0;
}
