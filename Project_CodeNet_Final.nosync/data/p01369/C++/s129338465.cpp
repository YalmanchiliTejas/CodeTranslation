#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<complex>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
#define EPS (long double) 1e-8
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};

int main(void) {
	map<char, int> m;
	m['a'] = 0;
	m['b'] = 0;
	m['c'] = 0;
	m['d'] = 0;
	m['e'] = 0;
	m['f'] = 0;
	m['g'] = 0;
	m['h'] = 1;
	m['i'] = 1;
	m['j'] = 1;
	m['k'] = 1;
	m['l'] = 1;
	m['m'] = 1;
	m['n'] = 1;
	m['o'] = 1;
	m['p'] = 1;
	m['q'] = 0;
	m['r'] = 0;
	m['s'] = 0;
	m['t'] = 0;
	m['u'] = 1;
	m['v'] = 0;
	m['w'] = 0;
	m['x'] = 0;
	m['y'] = 1;
	m['z'] = 0;
	while(1) {
		string s;
		cin>>s;
		if(s == "#") break;
		int res = 0;
		FOR(i, 1, s.size()) {
			if(m[s[i]] != m[s[i - 1]]) ++ res;
		}
		cout<<res<<endl;
	}
}