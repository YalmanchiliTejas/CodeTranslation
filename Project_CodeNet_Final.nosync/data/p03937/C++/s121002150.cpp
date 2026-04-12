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


//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define VI(v,n) vector<int> v(n)



int main() {
	int h, w;
	cin >> h >> w;
	char field[10][10];
	REP(i, h) {
		REP(j, w) {
			cin >> field[i][j];
		}
	}

	int px = 0, py = 0;
	while (px < w && py < h) {
		
		field[py][px] = '.';
		if (field[py][px - 1] == '#' || field[py - 1][px] == '#') {
			cout << "Impossible" << endl;
			return 0;
		}
		if (px == w - 1 && py == h - 1) {
			break;
		}
		if (field[py][px + 1] == '#' && field[py+1][px] == '#') {
			cout <<"Impossible" << endl;
			return 0;
		}
		else if (field[py][px + 1] == '#') {
			px++;
			//cout <<"px="<< px << endl;
		}
		else if (field[py+1][px] == '#') {
			py++;
			//cout << "py=" << py << endl;
		}
		else {
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << "Possible" << endl;


	return 0;
}

