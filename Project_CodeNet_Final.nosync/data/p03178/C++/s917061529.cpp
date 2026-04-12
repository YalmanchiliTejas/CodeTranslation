#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const int MOD=1e9+7;
int main()
{
	string k;
	cin>>k;
	int n=k.size();
	int d; cin>>d;
	int dp[2][10001][101]={};
	for(int i=1; i<(k[0]-'0'); i++){
		dp[1][0][i%d]+=1;
	}
	dp[0][0][(k[0]-'0')%d]+=1;
	for(int i=1; i<n; i++){
		for(int j=1; j<10; j++){
			dp[1][i][j%d]+=1;
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j=0; j<d; j++){
			for(int l=0; l<10; l++){
				dp[1][i+1][(j+l)%d]+=dp[1][i][j];
				dp[1][i+1][(j+l)%d]%=MOD;
			}
			for(int l=0; l<(k[i+1]-'0'); l++){
				dp[1][i+1][(j+l)%d]+=dp[0][i][j];
				dp[1][i+1][(j+l)%d]%=MOD;
			}
			dp[0][i+1][(j+(k[i+1]-'0'))%d]+=dp[0][i][j];
			dp[0][i+1][(j+(k[i+1]-'0'))%d]%=MOD;
		}
	}
	cout<<(dp[0][n-1][0]+dp[1][n-1][0])%MOD<<endl;
	return 0;
}