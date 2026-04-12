#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#define REP(i,n) for(int i=0;i<(int)n;i++)
#define REP1(j,n) for(int j=0;j<(int)n;j++)
#define REPS(i,n) for(int i=1;i<=(int)n;i++)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
using namespace std;
typedef long long ll;

/*int main(void) {
	int N, K,i=0,j=0;
	cin >> N >> K;
	int x[100000];
	int mintime = 0,a;
	REP(i, N) { 
		cin >> x[i]; 
	}
	if (N == 1 && K == 1)cout << "0" << endl;
	REP(i, K) {
		
	}
	mintime += abs(x);
}*/

int main() {
	int H, W, i = 0, j = 0;
	char a[100][100];
	cin >> H >> W;
	REP(i, H) {
		REP(j, W) {
			cin >> a[i][j];
		}
	}
	vector<bool> row(H, false);
	vector<bool> col(W, false);
	REP(i, H) {
		REP(j, W) {
			if (a[i][j] == '#') {
				row[i] = true;
				col[j] = true;
			}
		}
	}
	REP(i, H) {
		if (row[i]) {
			REP(j, W) {
				if (col[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}


