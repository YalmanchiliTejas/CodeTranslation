/* author : akshatjai258 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define mod int(1e9 + 7)
#define inf int(1e9)
#define endl "\n"
#define watch(x) cout << (#x) << " = " << (x) << endl
#define rep(i, n) for (int(i) = (0); (i) < (n); ++(i))
#define fi first
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define memf(a) memset(a, false, sizeof(a))
#define all(v) v.begin(), v.end()
#define se second
#define mp make_pair
#define pb push_back
#define w(x)  \
	int x;    \
	cin >> x; \
	while (x--)
#define ps(x, y) fixed << setprecision(y) << x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main()
{
	FIO;
	ll x;
	cin>>x;
	puts(x>=30?"Yes":"No");
	return 0;
}