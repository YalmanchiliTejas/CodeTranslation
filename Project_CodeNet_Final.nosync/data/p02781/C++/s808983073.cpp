#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

string s;
int k;
int dp[501][5][2];

int main(void){
	cin >> s;
	scanf("%d",&k);
	dp[0][0][0]=1;
	int n=s.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<=k;j++){
			for(int l=0;l<2;l++){
				for(int a=0;a<=9;a++){
					if(l==1){
						dp[i+1][j+(a!=0?1:0)][l]+=dp[i][j][l];
					}else if((s[i]-'0')>a){
						dp[i+1][j+(a!=0?1:0)][1]+=dp[i][j][l];
					}else if((s[i]-'0')==a){
						dp[i+1][j+(a!=0?1:0)][0]+=dp[i][j][l];
					}
				}
			}
		}
	}
	printf("%d\n",dp[n][k][0]+dp[n][k][1]);
	return 0;
}
