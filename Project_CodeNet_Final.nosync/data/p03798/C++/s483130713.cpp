#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define REP(i,a,n) for(int i = a;i < (n);i++)
#define RREP(i,a) for(int i = a;i >= 0;i--)
#define rep(i,n) for(int i = 0;i < (n);i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define range(x,min,max) ((min) <= (x) && (x) <= (max))
#define xyrange(x, minX, maxX, y, minY, maxY) (range(x, minX, maxX) && range(y, minY, maxY))

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};
const int INF = 0x3f3f3f3f;

int N;
string s;

string sim(string init_s) {
	string res = init_s;
	REP (i, 1, s.size() - 1) {
		if (res[i] == 'S' && s[i] == 'o') {
			res += res[i - 1];
		} else if (res[i] == 'S' && s[i] == 'x') {
			res += (res[i - 1] == 'S'? 'W' : 'S');
		} else if (res[i] == 'W' && s[i] == 'o') {
			res += (res[i - 1] == 'S'? 'W' : 'S');
		} else {
			res += res[i - 1];
		}
	}
	return res;
}

string solve() {
	s = s[s.size() - 1] + s;
	s += s[1];
	VS pats;
	pats.pb(sim("SS"));
	pats.pb(sim("WS"));
	pats.pb(sim("SW"));
	pats.pb(sim("WW"));
	for (auto& pat : pats) {
		if (pat[1] == pat[pat.size() - 1] && pat[0] == pat[pat.size() - 2]) return pat.substr(1, pat.size() - 2);
	}
	return "NA";
}

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	cin >> N >> s;
	string ans = solve();
	if (ans == "NA") {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}

