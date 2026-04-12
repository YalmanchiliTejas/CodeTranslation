#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using pi = pair<int,int>;
using pl = pair<ll,ll>;

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

ll ketawa(ll a) {
	if (a < 10)return a;
	return ketawa(a / 10) + a % 10;
}

int main() {
	
	double r1, r2;
	cin >> r1 >> r2;

	cout << setprecision(10) << (r1*r2) / (r1 + r2) << endl;;

	return 0;
}