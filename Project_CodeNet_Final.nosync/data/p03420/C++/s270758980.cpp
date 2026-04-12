#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second
ll n,k;
int main(){
	cin >> n >> k;
	if(k == 0) {
		cout << n * n << endl;
		return 0;
	}

	ll c = 0;
	FOR(b,k + 1,n) {
		if(b + k - 1 >= n) {
			continue;
		}
		ll m = n - (b + k - 1);
		ll l = m / b;
		c += l * (b - k);
		if(l * b != m) {
			c += min(m % b,b - k);
		}
	}
	c += (n - k) * (n - k + 1) / 2;
	cout << c << endl;
	return 0;
}
