#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int N,K;
char buf[105];
ll dp[105][2][4];

int main(){

	scanf("%s",buf);
	scanf("%d",&K);

	for(N = 0; buf[N] != '\0'; N++);

	for(int i = 0; i <= N; i++){
		for(int k = 0; k < 2; k++){
			for(int a = 0; a <= K; a++){
				dp[i][k][a] = 0;
			}
		}
	}

	//dp[桁][先頭からNと一致しているか][非0の数] = 場合の数

	dp[0][true][1] = 1; //先頭は非0
	dp[0][false][1] = (buf[0]-'0')-1;
	dp[0][false][0] = 1;

	for(int i = 1; i < N; i++){

		//true→true
		for(int k = 1; k <= K; k++){

			if(buf[i] != '0'){

				dp[i][true][k] += dp[i-1][true][k-1];
			}else{ //buf[i] == '0'

				dp[i][true][k] += dp[i-1][true][k];
			}
			//printf("dp[true][%d]:%lld\n",k,dp[i][true][k]);
		}
		//true→false
		for(int k = 1; k <= K; k++){

			if(buf[i] == '0'){

				//true→falseへは移れない

			}else{ //buf[i] > '0'

				dp[i][false][k] += dp[i-1][true][k]; //この桁を0にする
				dp[i][false][k] += dp[i-1][true][k-1]*(ll)((buf[i]-'0')-1); //この桁を1～(buf[i]-'0'-1)にする
			}
			//printf("dp[false][%d]:%lld\n",k,dp[i][false][k]);
		}

		//false→false
		for(int k = 0; k <= K; k++){

			//この桁を0にする
			dp[i][false][k] += dp[i-1][false][k];
			if(k == 0)continue;
			//この桁を1～9にする
			dp[i][false][k] += dp[i-1][false][k-1]*9;
			//printf("dp[false][%d]:%lld\n",k,dp[i][false][k]);
		}
	}

	printf("%lld",dp[N-1][true][K]+dp[N-1][false][K]);

	return 0;
}
