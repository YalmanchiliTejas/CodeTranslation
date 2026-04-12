#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 0
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) c.begin(),c.end()
static const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
static const int MOD = (int)(1e9 + 7);

class Dice {
private:
	//string d = "UFRLBD";
	string d = "RENSWL";
	map<char, string> mp;
public:
	vector<int> v; //UFRLBD:123456
	Dice(vector<int> v) :v(v) {
		mp[d[0]] = "2354";
		mp[d[1]] = "1463";
		mp[d[2]] = "1265";
		mp[d[3]] = "1562";
		mp[d[4]] = "1364";
		mp[d[5]] = "2453";
	};
	void roll(char c) {
		roll(mp[c]);
	}
	void roll(string s) {
		int tmp = v[s[0] - '1'];
		rep(i, 1, s.size())v[s[i - 1] - '1'] = v[s[i] - '1'];
		v[s[s.size() - 1] - '1'] = tmp;
	}
};

signed main() {

	for (int n; cin >> n&&n;) {
		vector<int> v(6); rep(i, 0, 6) { v[i] = i + 1; }
		Dice D(v);
		int ans = v[0];
		rep(i, 0, n) {
			string s; cin >> s;
			D.roll(s[0]);
			ans += D.v[0];
		}
		cout << ans << endl;
	}
	return 0;
}