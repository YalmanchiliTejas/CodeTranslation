//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define SORT(c) sort((c).begin(),(c).end())
#define ANS(ans) cout<<(ans)<<endl;
typedef vector<int> VI;


//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for (int i = 0; i < (n); ++i)


int main() {
	int h, w;
	cin >> h >> w;
	char field[100][100] = {};

	REP(i, h) {
		REP(j, w) {
			cin >> field[i][j];
		}
	}

	VI yoko(0);
	VI tate(0);
	REP(i, h) {
		REP(j, w) {
			if (field[i][j] == '#') {
				yoko.push_back(i);
				tate.push_back(j);
			}
		}
	}

	SORT(yoko);
	SORT(tate);

	yoko.erase(unique(yoko.begin(), yoko.end()), yoko.end());
	tate.erase(unique(tate.begin(), tate.end()), tate.end());

	REP(i, yoko.size()) {
		REP(j, tate.size()) {
			cout << field[yoko[i]][tate[j]];
		}
		cout << endl;
	}


	return 0;
}

