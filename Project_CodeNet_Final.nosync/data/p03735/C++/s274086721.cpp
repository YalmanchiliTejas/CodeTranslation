#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;


int T, n, m;

ll solve(vector<pll> v){
	sort(ALL(v));
	set<ll> s;
	REP(i, n) s.insert(v[i].second);
	ll ans = abs(v[0].first - v.back().first) * abs(*s.begin() - *s.rbegin());
	ll amin = v.back().first;
	ll amax = v.back().first;
	REP(i, n - 1){
		ll a, b; tie(a, b) = v[i];
		amin = min(amin, b);
		amax = max(amax, b);
		if(amin <= a) break;
		s.insert(a);
		ans = min(ans, abs(min(amin, v[i + 1].first) - max(amax, v.back().first)) * abs(*s.begin() - *s.rbegin()));
	}
	return ans;
}

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin >> n;
	vector<pll> v1, v2;
	REP(i, n){
		ll x, y;
		cin >> x >> y;
		if(x > y) swap(x, y);
		v1.eb(x, y);
		v2.eb(-y, -x);
	}
	
	cout << min(solve(v1), solve(v2)) << endl;
	return 0;
}
