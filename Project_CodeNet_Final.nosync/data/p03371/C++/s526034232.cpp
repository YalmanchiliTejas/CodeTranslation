#include<bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 32);
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
typedef vector<pair<ll, ll> > vp;
typedef vector<string> vs;
typedef vector<char> vc;
typedef list<ll> lst;
typedef pair<ll, ll> P;
template <class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

ll n, m, k, ans = 0, sum = 0, cnt = 0;
string s;
char c;

#define Endl endl

/*--------------------template--------------------*/


int main() {
	cin >> n >> m >> k;
	ll x, y;
	cin >> x >> y;
	ans = n * x + m * y;
	sum = INF;
	if(x>y){
		sum = y * k * 2 + (x - y) * n;
		chmin(sum, x * k * 2);
	}else{
		chmin(ans, x * k * 2 + (y - x) * m);
		chmin(ans, y * k * 2);
	}
	cout << min(ans, sum) << endl;
}