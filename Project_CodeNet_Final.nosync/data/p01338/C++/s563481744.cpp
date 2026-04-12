#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <list>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <set>
#include <memory.h>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <map>
#include <cassert>
#include <time.h>
#define _USE_MATH_DEFINES
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef pair<string, map<string, int> > Ps;
typedef vector<int> vec;
typedef vector<vec> mat;
const int INF = 1 << 30;
const double EPS = 1e-9;


int board[5][5];
int score[] = {
	0, 0, 60, 70, 80
};
int to_num1(int *a){
	int res = 0;
	for(int i = 0; i < 5; i++){
		res = res * 5 + a[i];
	}
	return res;
}

int dp[5][5 * 5 * 5 * 5 * 5];

int main(){
	int n;
	cin >> n;
	for(int t = 0; t < n; t++){
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				cin >> board[i][j];
			}
		}
		dp[0][to_num1(board[0])] = 0;

		int a[5];
		int b[5];
		int c[5];
		int d[5];

		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 5 * 5 * 5 * 5 * 5; j++){
				if(dp[i][j] == -1) continue;

				a[4] = j % 5;
				a[3] = (j / 5) % 5;
				a[2] = (j / 5 / 5) % 5;
				a[1] = (j / 5 / 5 / 5) % 5;
				a[0] = (j / 5 / 5 / 5 / 5) % 5;

				for(int k = 0; k < 1 << (2 * 4); k++){

					c[0] = (k & 3);
					c[1] = (k & 3) + ((k >> 2) & 3);
					c[2] = ((k >> 2) & 3) + ((k >> 4) & 3);
					c[3] = ((k >> 4) & 3) + ((k >> 6) & 3);
					c[4] = ((k >> 6) & 3);

					//cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << " " << c[4] << endl;
					int sum = 0;
					for(int l = 0; l < 5; l++){
						if(a[l] == 0){
						}else{
							sum += score[1 + (a[l] - 1 + c[l]) % 4];
						}

						if(i == 3){
							if(board[i+1][l] == 0){
								d[l] = 0;
							}else{
								d[l] = 1 + (board[i+1][l] - 1 + c[l]) % 4;
								sum += score[d[l]];
							}
						}

						if(board[i+1][l] == 0) b[l] = 0;
						else{
							b[l] = 1 + (board[i+1][l] - 1 + c[l]) % 4;
						}
					//	cout << b[l] << " ";
					}
			//		cout << endl;
				//	cout << sum << endl;
					dp[i+1][to_num1(b)] = max(dp[i+1][to_num1(b)], sum + dp[i][j]);
				//	cout << i << " " <<  dp[i+1][to_num1(b)] << endl;
				}
			}
		}
		int res = 0;
		for(int j = 0; j < 5; j++){
			for(int i = 0; i < 5 * 5 * 5 * 5 * 5; i++){
				res = max(res, dp[j][i]);
			}
			//cout << res << endl;
		}
		cout << res << endl;
	}
	return 0;
}