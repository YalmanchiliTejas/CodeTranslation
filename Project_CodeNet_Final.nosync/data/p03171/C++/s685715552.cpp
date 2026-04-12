#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<string>

using namespace std;

	pair < long long , long long > dp[3009][3009];
	long long val[3009];
	#define inf 1000000000990
	
int main(){

	long long sum = 0;
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> val[i];
		sum += val[i];
	}
	
	for(int i = 0; i < 3009; i++){
		for(int j = 0; j < 3009; j++){
			dp[i][j] = make_pair(0,0);
		}
	}
	
	for(int i = 1; i <= n; i++) dp[i][i] = make_pair(((n%2==0)?0:val[i]),((n%2==0)?val[i]:0));
	
	int igrac = ((n%2==0)?0:1);
	for(int d = 1; d <= n; d++){
		
		for(int i = 1, j = d; i<=n && j<=n; j++,i++){
			
			if(j + 1 <= n){
				if(igrac == 0){
					if(dp[i][j].first + val[j+1] > dp[i][j+1].first) dp[i][j+1] = make_pair(dp[i][j].first + val[j+1],dp[i][j].second);
				}	
				else{
					if(dp[i][j].second + val[j+1] > dp[i][j+1].second) dp[i][j+1] = make_pair(dp[i][j].first,dp[i][j].second + val[j+1]);
				}
			} 
			if(i - 1 > 0){
				if(igrac == 0){
					if(dp[i][j].first + val[i-1] > dp[i-1][j].first) dp[i-1][j] = make_pair(dp[i][j].first + val[i-1],dp[i][j].second);
				}	
				else{
					if(dp[i][j].second + val[i-1] > dp[i-1][j].second) dp[i-1][j] = make_pair(dp[i][j].first,dp[i][j].second + val[i-1]);
				}
			}
			
		}
		
		igrac++; igrac%=2;
		
	}
	
	cout << dp[1][n].first - dp[1][n].second << endl;
	
	

	return 0;
}