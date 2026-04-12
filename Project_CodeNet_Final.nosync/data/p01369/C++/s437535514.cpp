#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e7+1;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
typedef long long int ll;
typedef vector<ll> vi;
typedef vector < pair<ll, ll > > vp;
typedef vector <string> vs;
typedef vector <char> vc;
typedef list <ll> lst;

ll n,m, k, ans = 0, sum = 0, cnt = 0;
string s;
char c;

/*--------------------template--------------------*/

string r = "yuiophjklnm";

bool f(char a, char b)
{
	bool flga = 0, flgb = 0;
	REP(i, r.size())
	{
		if (a == r[i]) {
			flga = 1;
			break;
		}
	}
	REP(i, r.size())
	{
		if (b == r[i]) {
			flgb = 1;
			break;
		}
	}
	if (flga == flgb) {
		return 0;
	} else {
		return 1;
	}
}

int main()
{
	while (1) {
		cin >> s;
		if (s[0] == '#') {
			return 0;
		} else {
			cnt = 0;
			REP(i, s.size() - 1)
			{
				if (f(s[i], s[i + 1])) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}