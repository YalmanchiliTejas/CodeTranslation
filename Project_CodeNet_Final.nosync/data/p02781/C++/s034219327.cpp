#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin>>s;
	cin>>N;
	vector<vector<vector<long long int>>>dp(s.size()+1,vector<vector<long long int>>(2,vector<long long int>(N+1)));
	dp[0][1][0]=1;
	for(int i=0;i<s.size();i++){
		dp[i+1][0][0]=1;
		for(int j=0;j<2;j++){
			for(int l=0;l<=N;l++){
				for(int k=0;k<10;k++){
					if(k>(s[i]-'0')&&j)continue;
					if(!l&&!k)continue;
					if(l+(!!k)>N)continue;
					dp[i+1][(j)&&s[i]-'0'==k][l+(!!k)]+=dp[i][j][l];
				}
			}
		}
	}
	cout<<dp.back()[0][N]+dp.back()[1][N]<<endl;
}
