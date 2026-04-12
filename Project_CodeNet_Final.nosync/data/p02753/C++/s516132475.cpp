
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define _rep(n, a, b) for (ll n = (a); n <= (b); ++n)
#define _rev(n, a, b) for (ll n = (a); n >= (b); --n)
#define _for(n, a, b) for (ll n = (a); n < (b); ++n)
#define _rof(n, a, b) for (ll n = (a); n > (b); --n)
#define oo 0x3f3f3f3f3f3fll
#define ll long long
#define db double
#define eps 1e-8
#define bin(x) cout << bitset<10>(x) << endl;
#define what_is(x) cerr << #x << " is " << x << endl
#define met(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pdd pair<db, db>
#define pi acos(-1.0)
#define lowbit(x) x &(-x)
const ll maxn = 1e5 + 10;
const ll mod = 1e9;

signed main()
{
	string s;
	cin >> s;
	map<char, int> c;
	for(auto i:s){
		c[i]++;
	}
	if(c['A'] && c['B']){
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}
}
