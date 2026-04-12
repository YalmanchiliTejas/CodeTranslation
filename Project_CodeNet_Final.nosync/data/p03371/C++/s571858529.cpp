#include "bits/stdc++.h"

#define rep(a,b) for(int a = 0;a < b;a++)
#define REP(i, x, n) for(int i = x; i < n; i++)
#define P(a) cout << a << endl
#define mp(a,b) make_pair(a,b)
#define ssort(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define vP(v) for(int i = 0;i < v.size();i++){cout << v[i];if(i != v.size()-1)cout << endl;}
#define vcin(v,n) rep(i,n){int a;cin >> a;v.pb(a);}

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { 1, -1 , 0 , 0 };
int dy[] = { 0,  0,  1, -1 };
ll MOD = 1000000007;

long long stoi(string str) {
	long long ret;
	stringstream ss; ss << str;
	ss >> ret;
	return ret;
}

void solve() {
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll nopair = a*x + b*y;
	ll partpair = min(x, y) * 2 * c;
	ll onlypair = max(x, y) * 2 * c;
	if (x != y) {
		if (x < y) {
			partpair += (y - x)*b;
		}
		else {
			partpair += (x - y)*a;
		}
	}
	P(min(min(nopair, partpair),onlypair));
}

int main() {
	solve();
	return 0;
}
