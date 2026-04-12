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
constexpr long long MOD = 1'000'000'007; 

struct fast_io {
	fast_io(){
		std::cin.tie(nullptr);
		std::ios::sync_with_stdio(false);
	};
} ;
// } fio;

signed main(){
	cout<<fixed<<setprecision(10);
	
	int N;
	vector<int> A;
	
	cin>>N;
	
	A.resize(N);
	
	for(int i = 0; i < N; i++){
		cin>>A[i];
	}
	
	if(N%2 == 0) {
		vector<int> sum0(N/2+1), sum1(N/2+1);
		int ans = -INF;
		
		for(int i = 0; i < N/2; i++){
			sum0[i+1] += A[i * 2];
			sum1[i+1] += A[i * 2 + 1];
			sum0[i+1] += sum0[i];
			sum1[i+1] += sum1[i];
		}
		// cout<<sum1[N/2]<<endl;
		
		for(int i = 0; i <= N/2; i++){
			ans = max(sum0[i] - sum0[0] + sum1[N/2] - sum1[i], ans);
		}
		
		cout<<ans<<endl;
		
	} else {
		vector<vector<int>> dp(3, vector<int>(N/2+2, -INF));
		int ans = -INF;
		
		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[2][0] = 0;
		
		// dp[0][0] = dp[1][0] = dp[2][0] = 0;
		
		for(int i = 0; i < N/2+1; i++){
			// cout<<"i = "<<i<<endl;
			if(i + 1 != N/2+1) {
				dp[0][i+1] = max(dp[0][i] + A[i*2], dp[0][i+1]);
			} else {
				dp[0][i+1] = dp[0][i];
			}
			if(i + 1 != N/2+1) {
				dp[1][i+1] = max(dp[1][i] + A[i*2+1], dp[0][i] + A[i*2+1]);
			} else {
				dp[1][i+1] = dp[1][i];
			}
			
			// if()dp[2][i+1] = max(dp[2][i] + A[i*2], dp[1][i] + A[i*2]);
			dp[2][i+1] = max(dp[2][i] + A[i*2], dp[2][i+1]);
			if(i >= 1) dp[2][i+1] = max(dp[2][i+1],max(dp[1][i-1] + A[i*2], dp[0][i-1] + A[i*2]));
			
			// cout<<"<> "<<dp[0][i+1] <<" "<<dp[1][i+1] <<" "<<dp[2][i+1] <<endl;
		}
		
		ans = max(dp[0][N/2+1], max(dp[2][N/2+1],dp[1][N/2+1]));
		
		cout<<ans<<endl;
	}
	
	return 0;
}