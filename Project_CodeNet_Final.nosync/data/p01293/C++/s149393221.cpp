#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>

// BEGIN CUT HERE
#ifdef _MSC_VER
#include <agents.h>
#endif
// END CUT HERE 

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define MP make_pair
#define MT make_tuple
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int main(){
	string str = "__23456789TJQKA";
	map<char, int> m;
	rep(i, str.size()) m[str[i]] = i;

	char tr;
	while (cin >> tr, tr != '#'){
		vector<char> suite[4];
		vector<int> num[4];

		rep(i, 4) rep(j, 13){
			string s;
			cin >> s;
			num[i].push_back(m[s[0]]);
			suite[i].push_back(s[1]);
		}

		int cnt[2] = {};
		int led = 0;
		rep(i, 13){
			char leds = suite[led][i];
			P tbest = MP(-1, -1);
			P lbest = MP(-1, -1);
			rep(j, 4){
				if (suite[j][i] == tr){
					tbest = max(tbest, MP(num[j][i], j));
				}
				else if (suite[j][i] == leds){
					lbest = max(lbest, MP(num[j][i], j));
				}
			}
			int won = -1;
			if (tbest.first >= 0){
				won = tbest.second;
			}
			else{
				won = lbest.second;
			}
			++cnt[won & 1];
			led = won;
		}
		int team = cnt[1] > 6;
		cout << (team ? "EW " : "NS ") << cnt[team] - 6 << endl;
	}

	return 0;
}