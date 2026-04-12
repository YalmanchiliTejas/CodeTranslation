#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
vector<string> rotateClockwise(vector<string> g) {
    int n = g.size();
    int m = g[0].size();
    vector<string> res(m, string(n, '#'));
    rep(i, 0, n) rep(j, 0, m) res[j][n - i - 1] = g[i][j];
    return res;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/
 
 
 
 
 
 
int H, W;
vector<string> B;
//---------------------------------------------------------------------------------------------------
int solve() {
	int ma = -1, mi = inf;

	rep(y, 0, H) rep(x, 0, W) if (B[y][x] == 'B') {
		chmax(ma, y + x);
		chmin(mi, y + x);
	}

	return ma - mi;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) {
		string s; cin >> s;
		B.push_back(s);
	}

	int ans = 0;

	rep(d, 0, 4) {
		// rotate
		B = rotateClockwise(B);
		swap(H, W);

		chmax(ans, solve());
	}

	cout << ans << endl;
}
 
