#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <fstream>
using namespace std;
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string toStr(T x) { ostringstream sout; sout << x; return sout.str();}
typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

int num(string card) {
	switch(card[0]) {
	case 'A':
		return 14;
	case 'T':
		return 10;
	case 'J':
		return 11;
	case 'Q':
		return 12;
	case 'K':
		return 13;
	default:
		return card[0]-'0';
	}
}

char suit(string card) {
	return card[1];
}

int main() {
	char trump;
	while(cin >> trump, trump != '#') {
		vector<vs> card(4, vs(13));
		REP(i, 4) {
			REP(j, 13) {
				cin >> card[i][j];
			}
		}

		int ns = 0, ew = 0;
		int d = 0;
		REP(i, 13) {
			int best = -1, tbest = -1, twinner = -1, winner = -1;
			char ts = suit(card[d][i]);
			REP(j, 4) {
				char s = suit(card[j][i]);
				int n = num(card[j][i]);
				if(s == trump) {
					if(tbest < n) {
						tbest = n;
						twinner = j;
					}
				} else if(ts == s) {
					if(best < n) {
						best = n;
						winner = j;
					}
				}
			}
			if(twinner != -1) {
				if(twinner%2) {
					ew++;
				} else {
					ns++;
				}
				d = twinner;
			} else {
				if(winner%2) {
					ew++;
				} else {
					ns++;
				}
				d = winner;
			}
		}

		if(ns < ew) {
			cout << "EW " << ew-6 << endl;
		} else {
			cout << "NS " << ns-6 << endl;
		}
	}

	return 0;
}