#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<cmath>
#include<queue>
#include<limits>
#include<cassert>
#include<set>
#include<tuple>
#include<map>
#include<list>

#define PB push_back
#define ALL(a)  (a).begin(),(a).end()
#define DWN(a)  (a).begin(),(a).end(), greater<int>()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	map<char, int> mp[50];
	REP(i, n) {
		string s;
		cin >> s;
		REP(j, s.size()) {
			mp[i][s[j]]++;
		}
	}
	REP(i, 26) {
		int mi = 1000000000;
		REP(j, n) {
			mi = min(mi, mp[j][(char)('a' + i)]);
		}
		REP(j, mi) {
			cout << (char)('a' + i);
		}
	}
	cout << endl;
	return 0;
}