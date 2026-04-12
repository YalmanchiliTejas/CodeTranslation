#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int dp[305][305];
string dp2[305][305];

int main(void){
	while(1){
		string str;
		cin >> str;
		if(str=="#END")break;
		int res=0,id=0;
		for(int k=1;k<(int)str.size();k++){
			string str1=str.substr(0,k);
			string str2=str.substr(k);
			memset(dp,0,sizeof(dp));
			for(int i=0;i<str1.size();i++){
				for(int j=0;j<str2.size();j++){
					if(str1[i]==str2[j]){
						dp[i+1][j+1]=dp[i][j]+1;
					}else{
						dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
					}
				}
			}
			if(res<dp[str1.size()][str2.size()]){
				res=dp[str1.size()][str2.size()];
				id=k;
			}
		}
		string str1=str.substr(0,id);
		string str2=str.substr(id);
		for(int i=0;i<=str1.size();i++){
			for(int j=0;j<=str2.size();j++){
				dp2[i][j]="";
			}
		}
		for(int i=0;i<str1.size();i++){
			for(int j=0;j<str2.size();j++){
				if(str1[i]==str2[j]){
					dp2[i+1][j+1]=dp2[i][j]+str1[i];
				}else{
					if(dp2[i][j+1].size()<=dp2[i+1][j].size())dp2[i+1][j+1]=dp2[i+1][j];
					if(dp2[i][j+1].size()>dp2[i+1][j].size())dp2[i+1][j+1]=dp2[i][j+1];
				}
			}
		}
		cout << dp2[str1.size()][str2.size()] << endl;
	}
	return 0;
}