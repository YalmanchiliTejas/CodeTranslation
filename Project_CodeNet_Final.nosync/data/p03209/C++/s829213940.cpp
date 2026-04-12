#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int INF = 987654321;
const ll MOD = 1000000007;
//const long double PI = (acos(-1));
//const long double EPS = 0.0000000001;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

ll len[51];
ll cnt[51];

void precal() {
	len[0] = 1;
	cnt[0] = 1;
	rep(i,1,51) {
		len[i] = len[i-1] * 2 + 3;
		cnt[i] = cnt[i-1] * 2 + 1;
	}
}

ll n, x;

ll f(ll n, ll x) {
	//cout << n << ", " << x << endl;
	if(x == 0) {
		return 0;
	} else if(n == 0) {
		return 1;
	} else if(len[n] == x || len[n] == x+1) {
		return cnt[n];
	}

	ll y = len[n-1];
	ll ret = 0;
	if(x >= y+1) {
		ret += cnt[n-1];
		x -= (y+1);
	} else {
		return f(n-1, x-1);
	}

	if(x >= 1) {
		ret++;
		x -= 1;
	} else {
		return ret;
	}

	if(x > 0) 
		ret += f(n-1, x);
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("in.txt", "r", stdin);
	precal();
	cin >> n >> x;
	cout << f(n, x) << endl;
	return 0;
}