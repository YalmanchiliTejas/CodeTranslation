#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <numeric>
using namespace std;
typedef long long int ll;

ll dp[110][2][110];

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	string s; cin >> s;
	int kk; cin >> kk;
	dp[0][0][0]=1;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<=kk;k++){
				if(dp[i][j][k]==0)continue;
				if(j==0){
					for(int l=0;l<=s[i]-'0';l++){
						if(l==0){
							if(s[i]-'0'!=0)dp[i+1][1][k]+=dp[i][j][k];
							else dp[i+1][0][k]+=dp[i][j][k];
						}
						else if(l<s[i]-'0'){
							dp[i+1][1][k+1]+=dp[i][j][k];
						}
						else{
							if(s[i]-'0'==0)dp[i+1][0][k]+=dp[i][j][k];
							else dp[i+1][0][k+1]+=dp[i][j][k];
						}
					}
				}
				else{
					for(int l=0;l<=9;l++){
						if(l)dp[i+1][1][k+1]+=dp[i][j][k];
						else dp[i+1][1][k]+=dp[i][j][k];
					}
				}
			}
		}
	}
	cout << dp[s.size()][1][kk]+dp[s.size()][0][kk] << endl;
}