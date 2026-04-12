#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 0
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

//split delimiter??§?????????
vector<string> split(const string& input, char delimiter) {
	vector<string> ret;
	istringstream stream(input);
	string s;
	while (getline(stream, s, delimiter)) ret.push_back(s);
	return ret;
}

signed main() {
	for (string S; cin >> S&&S != "#";) {
		vector<string> s = split(S, '/');
		int h = s.size();
		int w = 0;
		rep(i, 0, s[0].size()) {
			if (s[0][i] == 'b')w++;
			else w += s[0][i] - '0';
		}
		dump(h);
		dump(w);
		vector<vector<char>> v(h, vector<char>(w, '.'));
		rep(i, 0, h) {
			int j = 0;
			rep(k, 0, s[i].size()) {
				if (s[i][k] == 'b') {
					v[i][j] = 'b';
						j++;
				}
				else j += s[i][k] - '0';
			}
		}
		if(DBG)rep(i, 0, v.size()) {
			cout << v[i][0];
			rep(j, 1, v[i].size()) { cout << " " << v[i][j]; }
			cout << endl;
		}
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		swap(v[a][b], v[c][d]);
		if (DBG)rep(i, 0, v.size()) {
			cout << v[i][0];
			rep(j, 1, v[i].size()) { cout << " " << v[i][j]; }
			cout << endl;
		}
		string ans = "";
		rep(i, 0, h) {
			if (i != 0)ans += "/";
			int cnt = 0;
			rep(j, 0, w) {
				if (v[i][j] == '.')cnt++;
				else {
					if(cnt)ans += to_string(cnt);
					ans += 'b';
					cnt = 0;
				}
			}
			if(cnt)
				ans += to_string(cnt);
		}
		cout << ans << endl;
	}
	return 0;
}