#include<map>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>

#define REP(i,x,y) for(ll i=x;i<=y;i++)
typedef long long ll;
using namespace std;

ll a[60];

bool ok(ll x, ll n) {
	if (x < 0) {
		return false;
	}
	ll b[60];
	REP(i, 1, n) {
		b[i] = a[i] + x;
	}
	ll cnt = 0;
	REP(i, 1, n) {
		ll t = a[i] + x - n + 1;
		if (t >= 0) {
			if (t%(n+1) == 0) {
				cnt += t / (n+1);
			}
			else {
				cnt += t / (n+1) + 1;
			}
		}
	}
	return cnt <= x;
}

int main() {
	ll n;
	cin >> n;
	bool flag = 1;
	REP(i, 1, n) {
		cin >> a[i];
		if (a[i] > n - 1) {
			flag = 0;
		}
	}
	if (flag) {
		cout << 0 << endl;
		return 0;
	}
	ll lb = 0; ll ub = 1000000000000000000;
	while (ub - lb > 1)
	{
		ll mid = (ub + lb) / 2;
		if (ok(mid,n)) {
			ub = mid;
		}
		else {
			lb = mid;
		}
	}
	//cout << ub << endl;
	REP(i, -1000000, 1000000) {
		if (ok(ub + i, n)) {
			cout << ub + i << endl;
			return 0;
		}
	}
}