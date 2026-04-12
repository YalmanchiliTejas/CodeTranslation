#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repe(i, n) for(int i=0;i<=(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

ll dfs(ll index, ll length) {
//	cout << index << " " << length << endl;
	if (index == 1) {
		return 0;
	} else if (length == 5) {
		if (index == 1) return 0;
		else if (index == 2) return 1;
		else if (index == 3) return 2;
		else if (index == 4) return 3;
		else return 3;
	} else if (index == length / 2 + 1) {
//		cout << "just" << endl;
		return index / 2 + 1;
	} else if (index < length / 2 + 1) {
//		cout << "min" << endl;
		return dfs(index - 1, length / 2 - 1);
	} else {
//		cout << "max" << endl;
		return ((length / 2 + 1) / 2 + 1) + dfs(index - (length / 2 + 1), length / 2 - 1);
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n, x;
	cin >> n >> x;
	
	ll cnt = 1;
	rep(i, n) {
		cnt = 2 * cnt + 3;
	}
//	cout << cnt << endl;
//	if (x == cnt / 2 + 1) {
// 	    cout << x / 2 + 1 << endl;
//	} else (x < cnt / 2 + 1){
//
//	}
	
	cout << dfs(x, cnt) << endl;
	
	return 0;
}