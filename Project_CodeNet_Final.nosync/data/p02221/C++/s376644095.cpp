#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>

using namespace std;

#define int long long
#define endl "\n"

constexpr long long INF = (long long)1e18;
long long MOD; 

struct fast_io {
	fast_io(){
		std::cin.tie(nullptr);
		std::ios::sync_with_stdio(false);
	};
} ;
// } fio;

int N;
string S;
vector<int> P;
vector<vector<int>> dp;

int solve(int d, int e, int c){
	int D = d%MOD;
	int E = e%MOD;
	
	int a = P[d];
	int b = P[e];
	
	if(a > b) swap(a, b);
	
	if(c == 1) {
		if(S[b - a - 1] == '1') {
			return b;
		} else {
			return a;
		}
	}

	if(dp[c][D]){
		return dp[c][D];
	}
	
	int f = solve(d, d + (1<<(c-2)), c-1);
	int g = solve(e, e + (1<<(c-2)), c-1);
	
	if(f > g) swap(f, g);
	
	if(S[g - f - 1] == '1')  dp[c][D] = g;
	else dp[c][D] = f;
	
	return dp[c][D];
}

signed main(){
	cout<<fixed<<setprecision(10);
	
	
	cin>>N;
	
	cin>>S;
	
	MOD = (1<<N);
	
	P.resize(1<<(N+1));
	dp.resize(N+1, vector<int>(1<<N));
	
	for(int i = 0; i < 1<<N; i++){
		cin>>P[i];
		P[i + (1<<N)] = P[i];
	}
	
	for(int i = 0; i < 1<<N; i++){
		cout<<solve(i, i + (1<<(N-1)), N)<<endl;
	}
	
	return 0;
}
