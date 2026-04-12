#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<cstdio>
#include<stack>
#include<queue>
#include<fstream>
#include<cstdio>
#include<deque>
#include<iomanip>
#include <numeric>

using namespace std;
#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);(i)--)
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
#define MIN(a,b) a=min((a),(b))
#define MAX(a,b) a=max((a),(b))
#define SIZE(v) (int)v.size()
const double pi = acos(-1.0);

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef deque<ll> dll;
typedef pair<string, int> P;
#define mod 1e9 + 7;
ll gcd(ll x, ll y)
{
	ll r;
	while ((r = x % y) != 0)
	{
		x = y;
		y = r;
	}
	return y;
}
ll lcm(ll x, ll y)
{
	x /= gcd(x, y);
	y /= gcd(x, y);
	return (x * y);
}

int ab[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	ll h, w;
	cin >> h >> w;
	char s[110][110];
	rep(i, h) rep(j,w)cin >> s[i][j];
	vi v,q;
	rep(i, h) {
		bool x = true;
		rep(j, w) {
			if (s[i][j] == '.') continue;
			else {
				x = false;
				break;
			}
		}
		if (x) v.pb(i);
	}
	rep(i, w) {
		bool x = true;
		rep(j, h) {
			if (s[j][i] == '.') continue;
			else{
				x = false;
				break;
			}
		}
		if (x) q.pb(i);
	}
	rep(i, h) {
		bool x = true;
		rep(a, v.size()) if (v[a] == i) x = false;
		if (x) {
			rep(j, w) {
				x = true;
				rep(a, q.size()) if (q[a] == j) x = false;
				if (x) {
					cout << s[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}