#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

#define DIV 1000000007

using namespace std;

int dp[205][205][420];
//int dp[55][55][55][55];
int H, W;
int a[205][205];

int main(){
	cin >> H >> W;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < H; i++){
		for(int k = 0; k < H; k++){
			for(int m = 0; m < H + W; m++){
				dp[i][k][m] = -INT_MAX;
			}
		}
	}
	dp[0][0][0] = 0;

	for(int i = 0; i < H; i++){
		for(int k = 0; k < H; k++){
			for(int m = 0; m < H + W - 1; m++){
				int j = m - i;
				int l = m - k;
				if(i == k && j == l){
					if(i != H - 1){
						if(k != H - 1){
							dp[i+1][k+1][i+1+j] = max(dp[i+1][k+1][i+1+j] , dp[i][k][m] + a[i][j]);
						}
						if(l != W - 1){
							dp[i+1][k][i+1+j] = max(dp[i+1][k][i+1+j], dp[i][k][m] + a[i][j]);
						}
					}
					if(j != W - 1){
						if(k != H - 1){
							dp[i][k+1][i+j+1] = max(dp[i][k+1][i+j+1], dp[i][k][m]+ a[i][j]);
						}
						if(l != W - 1){
							dp[i][k][i+j+1] = max(dp[i][k][i+j+1], dp[i][k][m]+ a[i][j]);
						}
					}

				}else{
					if(i != H - 1){
						if(k != H - 1){
							dp[i+1][k+1][m+1] = max(dp[i+1][k+1][m+1], dp[i][k][m]+ a[i][j] + a[k][l]);
						}
						if(l != W - 1){
							dp[i+1][k][m+1] = max(dp[i+1][k][m+1], dp[i][k][m] + a[i][j] + a[k][l]);
						}
					}
					if(j != W - 1){
						if(k != H - 1){
							dp[i][k+1][m+1] = max(dp[i][k+1][m+1], dp[i][k][m] + a[i][j] + a[k][l]);
						}
						if(l != W - 1){
							dp[i][k][m+1] = max(dp[i][k][m+1], dp[i][k][m] + a[i][j] + a[k][l]);
						}
					}
				}
			}
		}
	}
	cout << dp[H-1][H-1][H-1+W-1] + a[H-1][W-1] << endl;
}
