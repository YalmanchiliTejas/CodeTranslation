#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>

#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=m-1;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define PB(a) push_back(a)
#define INF 1000000001
#define MOD 1000000007

using namespace std;


int main() {
	string R = "yuiophjklnm";
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	while (cin >> s&&s != "#") {
		int a=R.find(s[0]);
		int cnt = 0;
		FOR(i, 1, s.size()) {
			if (a!=R.find('a')) {
				if (R.find(s[i])==R.find('a')) {
					cnt++;
					a = R.find('a');
				}
			}
			else {
				if (R.find(s[i])!=R.find('a')) {
					cnt++;
					a = 1;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}