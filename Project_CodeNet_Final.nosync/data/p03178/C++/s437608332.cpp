#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
// vector push_back push front top empty pop make_pair long long insert begin end  
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair <int,int> > vpi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define B begin()
#define RB rbegin()
#define E end()
#define RE rend()
#define Z size()
#define REP(i,a,b) for (int i = a; i < b; i++)
#define L length()
#define show(a) cerr << " *** " << a << endl;
#define show1(a) cerr << " /// " << a << endl;
#define valid(a,b,c) (a >= b && a < c ? 1 : 0)
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const int mod = (int)1e9 + 7;
void ads(ll &a, ll b){a += b;if (a >= mod)a -= mod;}
void mis(ll &a, ll b){a -= b;if (a >= mod)a -= mod; if (a < 0)a += mod;}
ll gcd(ll a, ll b) {return (b==0? a:gcd(b,a%b));}
ll egcd(ll a, ll b, ll & x, ll & y) {if (a == 0){x = 0;y = 1;return b;}ll x1, y1;ll d = egcd(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
ll mbinp(ll a, ll b){a %= mod;if (b == 0)return 1;ll ans = mbinp(a, b/2);ll tmp = (ans * ans) % mod;if (b % 2)return ((tmp * a) % mod);return ((tmp) % mod);}
ll binp(ll a, ll b){if (b == 0)return 1;ll ans = binp(a, b/2);ll tmp = (ans * ans);if (b % 2)return ((tmp * a));return ((tmp));}
string str;
const int maax = 10 * 1000 + 50;
ll dp[maax][110][2];
int d;

ll solve(int pos, int rem, int f)
{
	if (pos == str.L)
		return (rem == 0 ? 1 : 0);
	if (dp[pos][rem][f] != -1)
		return (dp[pos][rem][f]%mod);
	int lim = (f == 0 ? str[pos]-'0' : 9);
	ll res = 0;
	if (f == 0)
		REP(i,0,lim+1)
			ads(res,solve(pos+1,(rem+i)%d,(i != lim)));
	else
		REP(i,0,10)
			ads(res,solve(pos+1,(rem+i)%d,1));
	return (dp[pos][rem][f] = res);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str;
	cin >> d;
	memset(dp,-1,sizeof(dp));
	cout << (solve(0,0,0) - 1 +mod)%mod;	
}
