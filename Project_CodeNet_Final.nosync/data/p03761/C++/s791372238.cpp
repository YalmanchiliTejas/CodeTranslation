#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using IP = pair<int, int>;

const ll linf = 1LL << 62;
const int inf = 99999999;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const ll atcoder = 1e9 + 7;

#define Endl endl
#define mp make_pair
#define all(v) v.begin(),v.end()
#define pb push_back
#define pr(x) cout << x << endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
#define rep(i,n) for(int i= 0;i<n;i++)

ll gcd(ll a, ll b) {//最大公約数
	if (a%b == 0)return b;
	else gcd(b, a%b);
}

ll lcm(ll a, ll b) {//最小公倍数
	return (a / gcd(a, b))*b;
}

int main() {

	int c[26] = { 0 };
	int cnt[26] = { 0 };
	int n;
	cin >> n;

	rep(i,n){
		string s;
		cin >> s;
		rep(j, s.length()) {
			if (i == 0) c[s[j] - 'a']++;
			else cnt[s[j] - 'a']++;	
		}
		if (i != 0) {
			rep(j, 26)chmin(c[j], cnt[j]);
			rep(j, 26)cnt[j] = 0;
		}
	}

	rep(i, 26) {
		rep(j, c[i]) {
			char a = 'a' + i;
			cout << a;
		}
	}
	cout << endl;

	//system("pause");
	return 0;
}