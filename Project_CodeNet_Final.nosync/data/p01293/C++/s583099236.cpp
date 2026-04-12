#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

static const char d[] = "23456789TJQKA";

int main() {
	char trump;
	while(cin >> trump && trump != '#') {
		int rank[13][4];
		char suit[13][4];
		REP(j,4)REP(i,13) {
			char r;
			cin >> r >> suit[i][j];
			rank[i][j] = find(&d[0], &d[13], r) - &d[0];
		}
		int pt[] = {-6, -6};
		int leader = 0;
		REP(i,13) {
			char led = suit[i][leader];
			REP(j,4)if(suit[i][j] == trump)
				led = trump;
			int w = 0, g = -1;
			REP(j,4)if(suit[i][j] == led && g < rank[i][j])
				g = rank[i][w = j];
			pt[w%2]++;
			leader = w;
		}
		int w = pt[0] < pt[1];
		cout << (w ? "EW " : "NS ") << pt[w] << endl;
	}
	
	return 0;
}