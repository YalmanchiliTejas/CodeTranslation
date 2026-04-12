#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using vi = vector<int>;

const ll linf = 1LL << 62;
const int inf = 999999;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const ll atcoder = int(1e9 + 7);

#define Endl endl
#define pr(x) cout << x << endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
#define all(x) x.begin(),x.end()
#define atcoder(int)1e9+7
#define rep(i,n) for(int i = 0;i<n;i++)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)


ll gcd(ll a, ll b) {//最大公約数
	if (a%b == 0)return b;
	else gcd(b, a%b);
}

ll lcm(ll a, ll b) {//最小公倍数
	return (a / gcd(a, b))*b;
}

int  main() {
	
	int  h, w;
	cin >> w >> h;
	char c[10][10];
	int cnt = 0;

	rep(i, h) rep(j,w) cin >> c[i][j];
	rep(i, h) rep(j, w) if (c[i][j] == '#')cnt++;

	if (h + w - 1 == cnt)pr("Possible");
	else pr("Impossible");

	return 0;

}