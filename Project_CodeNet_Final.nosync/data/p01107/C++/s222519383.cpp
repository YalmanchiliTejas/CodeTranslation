#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

// #define DEBUG_MODE
#ifdef DEBUG_MODE
#define dump(x) cout << #x << " : " << x << endl
#define LINE cout << "line : " << __LINE__ << endl
#define dumpV(v) cout << #v << " : ["; for(auto& t : v) cout << t << ", "; cout<<"]" << endl
#define STOP assert(false)
#else
#define dump(x) ;
#define LINE 	;
#define dumpV(v);
#define STOP 	;
#endif

namespace std {
template<class S, class T>
ostream &operator <<(ostream& out, const pair<S, T>& a) {
	out << '(' << a.fi << ", " << a.se << ')';
	return out;
}
}


int dx[] = {0, 1, 0, -1};
int dy[] = { -1, 0, 1, 0};

void addWall(vector<string>& s, int& H, int& W, char wall = '#') {
	s.insert(s.begin(), string(W, wall));
	s.push_back(string(W, wall));
	for (auto& t : s) t = wall + t + wall;
	H = s.size();
	W = s[0].size();
}

int main() {
	int H, W;
	while (cin >> H >> W, H, W) {
		vector<string> s(H);
		rep(i, H) cin >> s[i];
		pii UL{1, 1}, UR{1, W}, DR{H, W}, DL{H, 1}; //(y, x)
		addWall(s, H, W);
		{
			// pre_calc
			vector<pii> path;
			set<pii> used;
			pii now = UL, nxt;
			path.pb(UL);
			used.insert(UL);
			int dir = 1;
			while (1) {
				nxt = make_pair(-1, -1);
				rep(i, 4) {
					int nx = now.se + dx[(dir + i + 3) % 4], ny = now.fi + dy[(dir + i + 3) % 4];
					if (s[ny][nx] == '#') continue;
					nxt = make_pair(ny, nx);
					(dir += i + 3) %= 4;
					break;
				}
				if(nxt == make_pair(-1, -1)) break;
				if (nxt == UL) break;
				if (used.count(nxt)) {
					while (path.back() != nxt) {
						pii p = path.back();
						s[p.fi][p.se] = '#';
						used.erase(p);
						path.pop_back();
					}
				}
				used.insert(nxt);
				path.pb(nxt);
				now = nxt;
			}
		}
		LINE;
		int dir = 1;
		set<pii> used;
		pii now = UL, nxt;
		used.insert(now);
		while (1) {
			nxt = now;
			rep(i, 4) {
				int nx = now.se + dx[(dir + i + 3) % 4], ny = now.fi + dy[(dir + i + 3) % 4];
				if (s[ny][nx] == '#') continue;
				nxt = make_pair(ny, nx);
				(dir += i + 3) %= 4;
				break;
			}
			if (nxt == now || used.count(nxt)) break;
			used.insert(nxt);
			now = nxt;
		}
		bool f = nxt == UL;
		f &= used.count(UL);
		f &= used.count(UR);
		f &= used.count(DR);
		f &= used.count(DL);
		rep(i, H) dump(s[i]);
		cout << (f ? "YES" : "NO") << endl;
	}
	return 0;
}