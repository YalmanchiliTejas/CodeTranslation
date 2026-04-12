#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;

int main(){
	char s[110], c;
	int l = 0;
	while((c=getchar()) != '\n') s[l++] = c;

	int dp[l+1][4][2] = {0};
	dp[0][0][0] = 1;
	for(int i=0; i<l; i++) for(int j=0; j<4; j++) for(int k=0; k<2; k++){
		int d = s[i] - '0';
		for(int nd=0; nd<10; nd++){
			int nonz = j + (nd>0);
			if(nonz>3) continue;
			if(k==0){
				if(nd<d) dp[i+1][nonz][1] += dp[i][j][k];
				else if(nd==d) dp[i+1][nonz][0] += dp[i][j][k];
				else continue;
			}else dp[i+1][nonz][1] += dp[i][j][k];
		}	
	}

	int k; scanf("%d", &k);
	printf("%d\n", dp[l][k][0]+dp[l][k][1]);
	return 0;
}
