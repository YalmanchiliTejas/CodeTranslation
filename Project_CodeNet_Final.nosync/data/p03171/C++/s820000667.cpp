/*
	@author: cheerioskun
*/
#pragma GCC target("popcnt")
#include "bits/stdc++.h"
#define f first
#define sc second
#define pb push_back
#define MOD 1000000007L
#define inf 0x3f3f3f3f
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
typedef std::vector<int> vi;
typedef std::pair<int, int> pii;
using namespace std;

ll a[3003], dp[3003][3003][2];

int main(){
	fast_io
	int N;
	cin>>N;
	for(int i = 0;i < N; ++i){
		cin>>a[i];
	}
	for(int i = 0;i < N; ++i){
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}
	for(int l = 2; l <= N; ++l){
		for(int i = 0;i + l <= N; ++i){
			// Set the 0 dp
			dp[i][i + l - 1][0] = max(a[i] + dp[i + 1][i + l - 1][1], dp[i][i + l - 2][1] + a[i + l - 1]);
			// Set the 1 dp
			dp[i][i + l - 1][1] = min(-a[i] + dp[i + 1][i + l - 1][0], dp[i][i + l - 2][0] - a[i + l - 1]);
		}
	}
	cout<<dp[0][N-1][0]<<endl;
	#ifndef ONLINE_JUDGE
    	cout<<"Time Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}

