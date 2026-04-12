#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

#define int long long
#define endl "\n"

constexpr long long INF = (long long)1e18;
constexpr long long MOD = 998244353; 

struct fast_io {
	fast_io(){
		std::cin.tie(nullptr);
		std::ios::sync_with_stdio(false);
	};
} fio;

signed main(){
	cout<<fixed<<setprecision(10);
	
	constexpr int MAX = 3100;
	int N, S;
	int ans = 0;
	vector<int> A;
	vector<int> dp(MAX);
	vector<int> dp2(MAX);
	
	cin>>N>>S;
	
	A.resize(N);
	// dp.resize(MAX):
	
	for(int i = 0; i < N; i++){
		cin>>A[i];
	}
	
	dp2[0] = 1;
	
	for(int i = 0; i < N; i++){
		vector<int> next(MAX);
		
		// cout<<endl<<"i = "<<i<<endl;
		
		for(int k = 0; k < MAX; k++){
			next[k] += dp[k];
			next[k] %= MOD;
			if(k+A[i] < MAX){
				next[k+A[i]] += dp[k];
				next[k+A[i]] %= MOD;
			}
		}
		
		next[A[i]] += (i+1);
		next[A[i]] %= MOD;
		
		for(int j = 0; j < MAX; j++){
			dp[j] = next[j];
			
			// cout<<"j = "<<j<<" dp = "<<dp[j]<<" "<<dp2[j]<<endl;
			if(j == S){
				ans += dp[j];
				ans %= MOD;
			}
		}
		
	}
	
	cout<<ans<<endl;
	
	return 0;
}