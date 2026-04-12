#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

char buf[301],right_buf[301],ans[301];
int dp[301][301],memo[301][301];

void func(){

	int length,right_length;
	for(length = 0; buf[length] != '\0'; length++){
		right_buf[length] = buf[length];
	}

	int ans_length = 0,right_start;

	for(int left_length = 1; left_length <= length-1; left_length++){

		right_length = length - left_length;
		right_start = left_length;

		if(left_length <= ans_length || right_length <= ans_length)continue;

		for(int a = 0; a <= max(right_length,left_length); a++){
			for(int b = 0; b <= max(right_length,left_length); b++)dp[a][b] = 0;
		}

		for(int i = 0; i < left_length; i++){
			for(int k = 0; k < right_length; k++){
				if(buf[i] == right_buf[right_start+k]){
					dp[i+1][k+1] = dp[i][k]+1;
					memo[i+1][k+1] = 0;
				}else{
					if(dp[i][k+1] >= dp[i+1][k]){
						dp[i+1][k+1] = dp[i][k+1];
						memo[i+1][k+1] = 1;
					}else{
						dp[i+1][k+1] = dp[i+1][k];
						memo[i+1][k+1] = -1;
					}
				}
			}
		}


		if(ans_length < dp[left_length][right_length]){
			ans_length = dp[left_length][right_length];

			stack<char> S;

			for(int i = left_length,k = right_length; i > 0 && k > 0;){

				if(memo[i][k] == 1){
					i--;
				}else if(memo[i][k] == -1){
					k--;
				}else{ //memo[i][k] == 0
					S.push(buf[i-1]);
					i--;
					k--;
				}
			}

			int index = 0;
			while(!S.empty()){
				ans[index++] = S.top();
				S.pop();
			}
		}
	}

	for(int i = 0; i < ans_length; i++)printf("%c",ans[i]);
	printf("\n");
}

int main(){

	while(true){
		scanf("%s",buf);
		if(buf[0] == '#')break;

		func();
	}

	return 0;
}