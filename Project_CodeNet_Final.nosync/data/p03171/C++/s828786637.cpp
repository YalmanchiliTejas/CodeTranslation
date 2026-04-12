#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3001;
long long int dp[MAXN][MAXN], a[MAXN], sums[MAXN];
int n;

long long int get_sum(int start, int end){
    if(start == 0){
        return sums[end];
    }
    return sums[end] - sums[start - 1];
}

long long int find_ans(int start = 0, int end = n - 1){
	if(start == end){
	    return 0;
	}else if(dp[start][end] != -1){
	    return get_sum(start,end) - dp[start][end];
	}else{
	    long long int ans1 = find_ans(start + 1, end);
	    long long int ans2 = find_ans(start, end - 1);
	    dp[start][end] = max(a[start] + ans1, a[end] + ans2);
	   // cout << "DP[" << start<< "]["<<end << "] = " << dp[start][end] << "\n"; 
	    return get_sum(start, end) - dp[start][end];
	}
}
  
int main(){
	cin >> n;
	long long int sum = 0;
	for(int i = 0; i < n; ++i){
      cin >> a[i];
      sum += a[i];
      sums[i] = sum;
    }
    
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            dp[i][j] = -1;
        }
    }
  
  	long long int ans = find_ans();
//   	cout << ans << "\n";
  	cout << sum - 2 * ans << "\n";
  	return 0;
}