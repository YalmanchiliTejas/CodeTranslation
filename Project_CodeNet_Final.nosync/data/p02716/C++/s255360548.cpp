#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 200005

ll N;
ll A[SIZE];
ll MIN[SIZE],MAX[SIZE];
ll dp[SIZE][3];

int main(){

	scanf("%lld",&N);

	for(int i = 1; i <= N; i++){

		scanf("%lld",&A[i]);
	}

	for(int i = 1; i <= N; i++){

		MAX[i] = (i+1)/2;

		int rest = N-i;
		MIN[i] = (N/2)-((rest+1)/2);
	}

	for(int i = 0; i <= N; i++){
		for(int k = 0; k < 3; k++){
			dp[i][k] = -HUGE_NUM;
		}
	}

	ll ans = -HUGE_NUM;

	for(int i = 1; i <= N; i++){
		for(int k = MIN[i]; k <= MAX[i]; k++){
			if(k == 0){

				dp[i][k-MIN[i]] = max(dp[i][k-MIN[i]],0LL);

			}else if(k == 1){

				dp[i][k-MIN[i]] = max(dp[i][k-MIN[i]],A[i]);

			}else{

				for(int pre = i-5; pre <= i-2; pre++){
					if(pre < 0)continue;
					for(int a = MAX[pre]; a >= MIN[pre]; a--){
						if(a == k-1 && dp[pre][a-MIN[pre]] != -HUGE_NUM){

							dp[i][k-MIN[i]] = max(dp[i][k-MIN[i]],dp[pre][a-MIN[pre]]+A[i]);
						}
					}
				}
			}

			if(k == N/2){
				ans = max(ans,dp[i][k-MIN[i]]);
			}
		}
	}

	printf("%lld\n",ans);

	return 0;
}
