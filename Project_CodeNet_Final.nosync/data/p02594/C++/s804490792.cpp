
/*
 *  Author :: Kattu37
 */

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define sortallr(x) sort(allr(x))
#define PI 3.1415926535897932384626
#define mod 1000000007

typedef pair<int, int>  pii;
typedef pair<ll, ll>  pll;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pll>   vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;

void solve()
{
	int x;
	cin >> x;

	if (x >= 30)
		cout << "Yes \n";
	else cout << "No \n";
}

int main(void)
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}
