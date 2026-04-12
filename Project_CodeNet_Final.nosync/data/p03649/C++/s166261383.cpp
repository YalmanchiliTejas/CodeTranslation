#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end());
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto _i:x) cout << _i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 1e-6
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long high, low, chs, lis[55], n, ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	REP (i, n) cin >> lis[i];
	int cnt = 0;
	int i = 0;
	while (cnt <= n) {
		int pos = i % n;
		if (lis[pos] >= n) cnt = 0;
		else cnt++;
		ans += lis[pos] / n;
		REP (j, n) if (j != pos) lis[j] += lis[pos] / n;
		lis[pos] %= n;
		i++;
	}
	cout << ans;
}	
