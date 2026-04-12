#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <utility>
using namespace std;

#define FOR(i,a,b) for(long long int i=(a);i<(b);i++)
#define REP(i,N) for(long long int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()

typedef long long ll;

#define PI acos(-1.0);

int n;
int dp[20][20];

int main(){
	while (cin >> n){
		if (n == 0)break;
		int x = n / 2 + 2, y = n / 2 + 1;
		dp[x][y] = 1;
		FOR(i, 2, n*n + 1){
			x++;
			y++;
			if (x > n){
				x = 1;
			}
			if (y > n){
				y = 1;
			}
			while (dp[x][y] != 0){
				x++;
				y--;
				if (x > n){
					x = 1;
				}
				if (y == 0){
					y = n;
				}
			}
			dp[x][y] = i;
		}
		FOR(i, 1, n + 1){
			FOR(j, 1, n + 1){
				printf("%4d", dp[i][j]);
			}
			cout << endl;
		}
		REP(i, n+1){
			REP(j, n + 1){
				dp[i][j] = 0;
			}
		}
	}
}