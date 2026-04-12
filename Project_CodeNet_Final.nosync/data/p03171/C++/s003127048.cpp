#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<bitset>
#include<cstdio>
#include<iomanip>

#define pii pair<int,int>
#define ll long long
#define IMAX 1000000007
#define in2d(i,j,H,W)(0<=i&&i<H&&0<=j&&j<W)

using namespace std;

int N;
vector<int>a;
vector<vector<ll> >dp;
int main(){
	cout<<fixed<<setprecision(11);
	
	cin>>N;
	a=vector<int>(N);for(int i=0;i<N;i++)cin>>a[i];
	dp=vector<vector<ll> >(N+1,vector<ll>(N+1,0));
	for(int i=0;i<=N;i++)dp[i][i]=0;
	for(int d=1;d<=N;d++)for(int l=0;l+d<=N;l++){
		int r=l+d;
		if((N-d)%2){
			dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r-1]);
		}else{
			dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r-1]);
		}
	}
	cout<<dp[0][N]<<endl;
	return 0;
}

