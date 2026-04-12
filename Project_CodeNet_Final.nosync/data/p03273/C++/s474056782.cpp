#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());
#define PAU system("pause")

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
const int EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 30);
const double PI = acos(-1);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	vvb V;
	REP(i, H) {
		string s;
		cin >> s;
		bool white = true;
		REP(i, SZ(s)) {
			if (s[i] == '#') {
				white = false;
				break;
			}
		}
		if (white)continue;
		vb newv(W,false);
		REP(i, SZ(s)) {
			char c = s[i];
			if (c == '.')newv[i] = true;
		}
		V.push_back(newv);
	}
	vb VB(W,false);
	REP(i, W) {
		bool white = true;
		REP(j, SZ(V)) {
			if (!V[j][i]) {
				white = false;
				break;
			}
		}
		if (white)VB[i] = true;
	}
	REP(i, SZ(V)){
		bool white = true;
		REP(j, W) {
			if (VB[j])continue;
			if (V[i][j])cout << ".";
			else cout << "#";
			white = false;
		}
		if (!white)cout << endl;
	}
	PAU;
	return 0;
}
