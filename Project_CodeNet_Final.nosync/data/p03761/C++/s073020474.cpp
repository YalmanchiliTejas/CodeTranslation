#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); i++)
#define SZ(x) ((int)(x).size())
typedef vector<string> VS;

int main() {
	int n; cin >> n;
	VS s(n); REP(i, n)cin >> s[i];

	for (char c = 'a'; c <= 'z'; c++) {

		int min = INT_MAX;
		REP(i, n) {
			int cnt = 0;
			REP(j, SZ(s[i])) {
				if (s[i][j] == c)cnt++;
			}
			min = min > cnt ? cnt : min;
		}

		REP(k, min)cout << c;

	}
	puts("");
}