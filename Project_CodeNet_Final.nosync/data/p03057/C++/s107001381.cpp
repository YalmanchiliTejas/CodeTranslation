#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

const int mod = 1000000007;

int n, m;
int col[200005];

int calc(int n){
	int fib[200005];
	fib[1] = fib[2] = 1;
	for(int i = 3; i <= n + 1; i++){
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	}
	
	// force first one to be 1, last one to be 0: fib[n - 1]
	// force first one to be 0: fib[n + 1]
	return (fib[n - 1] + fib[n + 1]) % mod;
}

int calc2(int n, int ub){
	assert(ub & 1);
	
	// want a bunch of numbers, in [2, ub], to sum to n
	
	ub++;
	ub = min(ub, n); // coz it can actually be HUGE
	
	int dp[200005]; // dp[i]: number of possible sums, that sum to i
	int cumu[200005];
	
	memset(dp, 0, sizeof(dp));
	memset(cumu, 0, sizeof(cumu));
	dp[0] = 1;
	cumu[0] = 1;
	
	for(int i = 2; i <= n; i += 2){
		// sum dp[l_index .. i - 2].. oh, only the even ones!
		int l_index = i - ub;
	//	printf("%d: sum %d..%d\n", i, l_index, r_index);
		dp[i] = cumu[i - 2];
		
		if(l_index > 0){
			dp[i] -= cumu[l_index - 2];
			if(dp[i] < 0){
				dp[i] += mod;
			}
		}
//		printf("%d: %d\n", i, dp[i]);
		cumu[i] = (cumu[i - 2] + dp[i]) % mod;
	}
	
	int ret = 0;
	
	for(int space = 0; space < ub; space++){
		// last 1 is at (n - space), leaving _ space at the end
		// where can the first 1 be?
		int most_remain = n - (space + 1);
		int least_remain = n - ub;
		
		if(most_remain & 1) most_remain--;
		
		// sum up dp[least_remain..most_remain] (even indices only)
		
		int combin = cumu[most_remain];
		if(least_remain > 0){
			combin = (combin - cumu[least_remain - 2] + mod) % mod;
		}
		ret = (ret + combin) % mod;
	}
	return ret;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		char c;
		scanf(" %c", &c);
		col[i] = (c == 'B');
	}
	
	if(col[1] != 0){
		for(int i = 1; i <= m; i++){
			col[i] = 1 - col[i];
		}
	}
	
	// WLOG first one is 0
	bool monochrome = true;
	for(int i = 2; i <= m; i++){
		if(col[i]){
			monochrome = false;
			break;
		}
	}
	if(monochrome){
		// ok as long as 1s are not adjacent
		printf("%d\n", calc(n));
		return 0;
	}else{
		// 00...010..010..0
		// each block of 0 is of add length
		// so, n odd -> definitely no solution
		// more conditions depending on specifics of col[]
		if(n % 2 == 1){
		 	printf("0\n");
		 	return 0;
		}
		int first_run = 0, subseq_run = n - 1;
		for(int i = 1; i <= m; i++){
			int len = 0;
			while(i + len <= m && col[i + len] == 0){
		 		len++;
		 	}
		 	if(first_run == 0){
		 		first_run = len;
		 	}else if(i + len <= m && len % 2 == 1){
		 		subseq_run = min(subseq_run, len);
		 	}
		 	i += len;
		}
		int ub = first_run + (first_run % 2 == 0);
		ub = min(ub, subseq_run);
		printf("%d\n", calc2(n, ub));
	}
	return 0;
}