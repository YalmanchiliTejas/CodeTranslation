#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//max=({});
//条件式が真ならwhileの中身を回し続ける
//printf("%d\n", ans);

//pairの入力
//vector<pair<ll, ll>>work(n);
//rep(i, n) {
//	ll a, b;
//	cin >> a >> b;
//	work[i] = make_pair(a, b);
//for(auto p:mp)(mapの探索)
//printf("%.10f\n",なんちゃら)

int g[15][15];
const int INF = 1001001001;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

//素因数分解
map<ll, ll>ins;
void facterize(ll n) {
	ll a = 2;
	while (n >= a * a) {
		if (n % a == 0) {
			ins[a]++;
			ins[a] = ins[a] % 1000000007;
			n /= a;
		}
		else {
			a++;
		}
	}
	ins[n]++;
}

vector<ll>relation[20], money(20, 1);
char s[110][110];
int dp[110][110];

int keta(int x) {
	int y = 0;
	while (x > 0) {
		y++;
		x /= 10;
	}
	return y;
}

ll a[110][110];

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int doll = min(a + b, c * 2);
	int ans = 0;
	if (x >= y) {
		ans = min(doll * x, doll * y + a * (x - y));
	}
	else {
		ans = min(doll * y, doll * x + b * (y - x));
	}
	cout << ans << endl;
	return 0;
}
