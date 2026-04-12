#include<bits/stdc++.h>
using namespace std;

long long dp[120][2][4];
// [iまでの桁][未満フラグ][0ではない値何個あるか]

int main(){
	for(int i=0;i<120;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<4;k++){
				dp[i][j][k]=0;
			}
		}
	}

	string n;	cin>>n;
	int k;	cin>>k;
	dp[0][0][0]=1;
	for(int i=0;i<n.length();i++){
		int D=n[i]-'0';
		for(int j=0;j<2;j++){
			for(int k=0;k<4;k++){
				for(int d=0; d<=((j==true)? 9:D); d++){
					// d: 最下位の数字として可能なもの
					if(k+(d!=0)>3)continue;
					dp[i+1][j||(d<D)][k+(d!=0)]+=dp[i][j][k];
				}
			}
		}
	}
	cout<<dp[n.length()][0][k]+dp[n.length()][1][k]<<endl;


	return 0;
}
