#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

void turn(int x, int y, int data[10][10]) {
	int dx[5] = {0,1,0,-1,0};
	int dy[5] = {0,0,1,0,-1};
	
	REP(i, 5) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!(nx >= 0 && nx < 10 && ny >= 0 && ny < 10)) continue;
		data[ny][nx]++;
	}
}

bool check(int data[10][10]) {
	bool res = true;
	
	REP(i, 10) if (data[9][i] & 1) res = false;
	
	return res;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int in[10][10];
		REP(i, 10) REP(j, 10) scanf("%d", &in[i][j]);
		
		bool ans[10][10];
		int data[10][10];
		
		REP(i, 1<<10) {
			memset(ans, 0, sizeof(ans));
			memcpy(data, in, sizeof(in));
			
			REP(j, 10) if ((i >> j) & 1) {
				ans[0][j] = true;
				turn(j, 0, data);
			}
			FOR(j, 1, 10) REP(k, 10) {	
				if (data[j - 1][k] & 1) {
					ans[j][k] = true;
					turn(k, j, data);
				}
			}
			
			if (check(data)) break;
		}
		
		REP(j, 10) REP(k, 10)
			printf("%d%c", ans[j][k] ? 1 : 0, k == 9 ? '\n' : ' ');
	}
	return 0;
}