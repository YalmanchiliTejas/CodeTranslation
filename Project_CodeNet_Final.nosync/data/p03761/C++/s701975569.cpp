#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <map>
#define ll long long
#define REP(i, x) for(int (i) = 0; (i) < (x); (i) ++)
#define pi 3.1415926535
const int MOD = 1000000007;
using namespace std;

int main() {
	int n;
	vector<vector<int>>alp(n, vector<int>(26, 0));
	cin >> n;
	string s;
	REP(i, n) {
		cin >> s;
		REP(j, s.size()) {
			alp[i][s[j]-'a']++;
		}
	}
	int min[26];
	REP(i, 26){
		int m = 10000000;
		REP(j, n) {
			if (alp[j][i] < m) {
				m = alp[j][i];
				min[i] = alp[j][i];
			}
		}
	}
	REP(i, 26) {
		char c = 'a';
		REP(j, min[i]) {
			printf("%c", c + i);
		}
	}
	return 0;
}