//It's really tough
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mem(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
const int N = 2e5 + 5;
const ll inf = 9e18 + 9;
const int mod = 1e9+7;
ll res;

void solve()
{
     long long n;
	int x, m;
	cin >> n >> x >> m;
	int prv = x;
	vector<bool> vis(m);
	vector<int> rep; rep.reserve((int) 1e6);
	while (!vis[prv]) {
		vis[prv] = 1;
		rep.push_back(prv);
		prv = (long long) prv * prv % m;
	}
	int i = 0;
	long long ans = 0;
	for (; i < (int) rep.size() && n; ++i) {
		if (rep[i] == prv) break;
		ans += rep[i];
		--n;
	}
	int period = (int) rep.size() - i;
	long long divs = n / period;
	int left = n % period;
	ans += ((long long) divs * accumulate(rep.begin() + i, rep.end(), (long long) 0) +
		accumulate(rep.begin() + i, rep.begin() + i + left, (long long) 0));
	cout << ans << endl;
}
 
int main()
{
    IOS;ll t = 1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}