#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
#include<string>
using namespace std;

typedef long long ll;
typedef pair<ll,int> P;

#define rep(i,x) for(int i = 0 ; i < x ; i ++)
#define rep1(i,x) for(int i = 1 ; i <= x ; i ++)
#define rrep(i,x) for(int i = x-1 ; i >= 0 ; i --)
#define pb push_back
#define sor(vec) sort(vec.begin(),vec.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define fr first
#define sc second

const ll M = 1000000007;

int main(){
	int h,w;
	int a[202][202];
	scanf("%d%d",&h,&w);
	rep1(i,h)rep1(j,w){
		scanf("%d",&a[i][j]);
	}
	
	static int dp[202][202][202] = {};
	dp[1][1][1] = a[1][1];
	for(int i = 2 ; i <= w ; i ++)dp[1][1][i] = dp[1][1][i-1] + a[1][i];
	for(int i = 2 ; i <= h ; i ++){
		for(int k = w ; k >= 2 ; k --){
			for(int j = 1 ; j < k ; j ++){
				dp[i][j][k] = max ( dp[i][j][k] , dp[i-1][j][k]+a[i][j]+a[i][k] );
				dp[i][j][k] = max ( dp[i][j][k] , dp[i][j-1][k]+a[i][j] );
				for(int K = k+1 ; K <= w ; K ++){
					dp[i][j][K] = max ( dp[i][j][K] , dp[i][j][K-1]+a[i][K] );
				}
			}
		}
	}
	int ret = 0;
	for(int i = 1 ; i <= w ; i ++){
		ret = max ( ret , dp[h][i][w] );
	}
	cout << ret << endl;
}
				
