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
	vector<int> A, dp(MAX);
	
	cin>>N>>S;
	
	A.resize(N);
	
	for(int i = 0; i < N; i++)
		cin>>A[i];
	
	for(int i = 0; i < N; i++){
		for(int k = MAX - A[i] - 1; k >= 0; k--)
			dp[k+A[i]] = (dp[k+A[i]]+dp[k])%MOD;
		dp[A[i]] = (dp[A[i]]+(i+1))%MOD;
		ans = (ans + dp[S])%MOD;
	}
	
	cout<<ans<<endl;
	
	return 0;
}