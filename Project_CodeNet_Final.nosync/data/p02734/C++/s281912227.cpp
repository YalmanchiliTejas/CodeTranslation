#include<bits/stdc++.h> 
using namespace std; 
const int mod = 998244353;
int dp[3001][3000];

int modu(int a){
	return ((a%mod)+mod)%mod;
}
long long modu(long long a){
	return ((a%mod)+mod)%mod;
}
int main() 
{ 
	
	int N,S;
	cin>>N>>S;
	vector<int>numbers(N);
	for(int i = 0;i<N;i++){
		cin>>numbers[i];
	}
	if(numbers[0]<=S){
		dp[numbers[0]][0] = 1;
	}
	dp[0][0] =1;
	long long ways = 0;
	
    for(int i =1;i<N;i++){
    	dp[0][i] = 1;
    	if(numbers[i]<=S){
	    	dp[numbers[i]][i] = modu(dp[numbers[i]][i] + i+1);
	    }
		for(int j=1;j<=S;j++){
			dp[j][i] = modu(dp[j][i]+dp[j][i-1]);
		}
    	for(int j=1;j<=S;j++){
    		
    		if(numbers[i]+j>S){
    			break;
			}
			else{
				dp[numbers[i]+j][i] = modu(dp[j][i-1] + dp[numbers[i]+j][i]);
			
			}
		}
		
	}
//	for(int i =0;i<=S;i++){
//		for(int j =0;j<N;j++){
//			cout<<dp[i][j]<<" ";
// 		}
//		cout<<endl;
//	}
	for(int j =1;j<N;j++){
		ways = modu(ways + dp[S][j]);
	}
	
    cout<<ways<<endl;
    return 0; 
} 
