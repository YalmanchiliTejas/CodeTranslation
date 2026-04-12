#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;

long long s[100005];

map<int, long long> memo[100005];

int N;

long long dp(int C, int k){
	//printf("%d %d\n", C, k);
	if(k == 0){
		return 0;
	}else if(memo[C].find(k) != memo[C].end()){
		return memo[C][k];
	}else{
		if((N-1)%C == 0 && N-1-(k-1)*C <= (k-1)*C){
			return memo[C][k] = -1LL << 61;
		}
		
		memo[C][k] = dp(C, k-1) + s[(k-1)*C] + s[N-1-(k-1)*C];
		/*if(memo[C][k] == 57){
			printf("57: %d %d\n", C, k);
		}else if(memo[C][k] == 59){
			printf("59: %d %d\n", C, k);
		}else if(memo[C][k] == 3){
			printf("3: %d %d\n", C, k);
		}else if(memo[C][k] == 13){
			printf("13: %d %d\n", C, k);
		}*/
		return memo[C][k];
	}
}


int main(){
	scanf("%d", &N);
	
	for(int i = 0; i < N; i ++){
		scanf("%lld", &s[i]);
	}
	
	long long ans = 0;
	for(int C = 1; C <= N; C ++){
		if((N-1)%C >= 0){
			for(int k = 0; k*C < N; k ++){
				ans = max(ans, dp(C, k));
			}
		}
	}
	
	printf("%lld", ans);
	return 0;
}
