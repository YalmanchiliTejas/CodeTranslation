//============================================================================
// Name        : JOI.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
int N;
string s;
char dp[4][100010];
int main(){
	cin>>N>>s;
	dp[0][0]='W';
	dp[0][1]='W';
	dp[1][0]='W';
	dp[1][1]='S';
	dp[2][0]='S';
	dp[2][1]='W';
	dp[3][0]='S';
	dp[3][1]='S';

	for(int i=1;i<N+2;i++){
		for(int j=0;j<4;j++){
			if(dp[j][i]=='S'){
				if(s[i%N]=='o'){
					if(dp[j][i-1]=='S')dp[j][i+1]='S';
					if(dp[j][i-1]=='W')dp[j][i+1]='W';
				}else{
					if(dp[j][i-1]=='S')dp[j][i+1]='W';
					if(dp[j][i-1]=='W')dp[j][i+1]='S';

				}
			}else{
				if(s[i%N]=='o'){
					if(dp[j][i-1]=='S')dp[j][i+1]='W';
					if(dp[j][i-1]=='W')dp[j][i+1]='S';
				}else{
					if(dp[j][i-1]=='S')dp[j][i+1]='S';
					if(dp[j][i-1]=='W')dp[j][i+1]='W';

				}
			}
		}
	}

	for(int i=0;i<4;i++){
		if(dp[i][0]==dp[i][N] && dp[i][1]==dp[i][N+1]){
			for(int j=0;j<N;j++){
				cout<<dp[i][j];
			}
			return 0;
		}

	}
	cout<<-1<<endl;


	return 0;
}
