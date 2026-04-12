#include <bits/stdc++.h>
#define x first
#define y second
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e18;
const long long mod = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
ll n,X,m,sum,ans;
ll d[300005],sd[300005];
int c[200005],st,i,en;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> X >> m;
	d[1] = sd[1] = ans = X;
	c[X] = 1;
	st = en = n+1;
	for(i = 2;i <= min(n,m+5);i++) {
		d[i] = d[i-1]*d[i-1]%m;
		sd[i] = sd[i-1]+d[i];
		ans += d[i];
		if(c[d[i]]) {
			st = i;
			break;
		}
		c[d[i]] = 1;
	}
	for(i = st+1;i <= min(n,m*2+10);i++) {
		d[i] = d[i-1]*d[i-1]%m;
		sum += d[i];
		sd[i] = sd[i-1]+d[i];
		if(d[i] == d[st]) {
			en = i;
			break;
		}
	}
	if(st == n+1) cout << ans;
	else {
		if(en == n+1) cout << ans+sum;
		else {
			cout << ans+sum*((n-st)/(en-st))+(sd[st+(n-st)%(en-st)]-sd[st]);
		}
	}
 	return 0;
}