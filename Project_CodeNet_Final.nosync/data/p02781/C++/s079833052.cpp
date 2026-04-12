#include <stdio.h>
#include <string>
#include <stdlib.h>
#include<vector>
#include<iostream>
using namespace std;




int main() {
	
	string s;
	cin >> s;
	int K;
	cin >> K;
	
	unsigned long long int dp1[101][10] = {0};
	unsigned long long int dp2[101][10] = {0};
	
	
	dp1[0][0] = 1;
	int tmp = (s[0] - '0');
	dp1[0][1] = tmp-1;
	
	
	// 未確定
	dp2[0][1] = 1;
	//dp2[0][0] = 1;
	
	
	//dp1[i][k] = dp[i][k-1]*9;
	
	for(int i=0;i<s.size()-1;++i){
		for(int k=0;k<=K;++k){
			//cout <<i << " "<< k <<endl;
			
			dp1[i+1][k+1] += dp1[i][k]*9;
			dp1[i+1][k] += dp1[i][k];
			
			int t = s[i+1] - '0';
			if(t == 0){
				dp2[i+1][k] += dp2[i][k]; // only 0
			}else{
				dp1[i+1][k] += dp2[i][k]; // only 0
				dp1[i+1][k+1] += dp2[i][k]*(t-1); // not 0 and t
				dp2[i+1][k+1] += dp2[i][k]; // only t
			}
		}
	}
	/*
	for(int i=0;i<10;++i){
		cout << dp1[i][0] << " ";
	}cout << endl;
	
	for(int i=0;i<10;++i){
		cout << dp1[i][1] << " ";
	}cout << endl;
	for(int i=0;i<10;++i){
		cout << dp1[i][2] << " ";
	}cout << endl;
	for(int i=0;i<10;++i){
		cout << dp2[i][0] << " ";
	}cout << endl;
	
	for(int i=0;i<10;++i){
		cout << dp2[i][1] << " ";
	}cout << endl;
	for(int i=0;i<10;++i){
		cout << dp2[i][2] << " ";
	}cout << endl;
	*/
	
	
	//cout << dp1[s.size()-1][K] <<" " << dp2[s.size()-1][K] <<endl;
	cout << dp1[s.size()-1][K] + dp2[s.size()-1][K] <<endl;
	
    return 0;
}
