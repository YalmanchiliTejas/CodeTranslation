#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(i, (v).size()) { cout << v[i]; if (i != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
///(?´????????`)(?´????????`)(?´????????`)(?´????????`)(?´????????`)(?´????????`)///
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	int n;
	cin >> s >> n;
	int ans1 = s[0] - '0';
	FOR(i, 1, s.size()) {
		if (i % 2 == 1) {
			if (s[i] == '+') {
				ans1 += s[i + 1] - '0';
			}
			else {
				ans1 *= s[i + 1] - '0';
			}
		}
		else continue;
	}
	int ans2 = 0, tmp = s[0] - '0';
	int i = 1;
	while (i < s.size()) {
		if (i % 2 == 1) {
			if (s[i] == '+') {
				ans2 += tmp;
				tmp = s[i+1]-'0';
			}
			else {
				tmp *= s[i+1] - '0';
			}
		}
		i += 2;
	}
	ans2 += tmp;


	if (ans1 == n) {
		if (ans2 == n)cout << 'U' << endl;
		else cout << 'L' << endl;
	}
	else {
		if (ans2 == n)cout << 'M' << endl;
		else cout << 'I' << endl;
	}



	return 0;
}