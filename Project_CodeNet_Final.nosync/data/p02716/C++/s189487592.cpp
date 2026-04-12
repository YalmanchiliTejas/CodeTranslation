#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;
typedef long long int ll;

ll dp[200200][2];
ll dp2[200200][2][2];

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<2;j++){
			dp[i][j]=-1e18;
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				dp2[i][j][k]=-1e18;
			}
		}
	}
	if(n%2==0){
		int u=n/2;
		dp[1][0]=a[0];
		dp[1][1]=a[1];
		for(int i=1;i<u;i++){
			for(int j=0;j<2;j++){
				if(j==0){
					dp[i+1][0]=max(dp[i+1][0],dp[i][j]+a[2*i]);
				}
				dp[i+1][1]=max(dp[i+1][1],dp[i][j]+a[2*i+1]);
			}
		}
		cout << max(dp[u][0],dp[u][1]) << endl;
	}
	else{
		int u=n/2;
		// a[n]を使わない場合
		dp[1][0]=a[0];
		dp[1][1]=a[1];
		for(int i=1;i<u;i++){
			for(int j=0;j<2;j++){
				if(j==0){
					dp[i+1][0]=max(dp[i+1][0],dp[i][j]+a[2*i]);
				}
				dp[i+1][1]=max(dp[i+1][1],dp[i][j]+a[2*i+1]);
			}
		}
		dp2[1][0][0]=a[n-1]+a[0];
		dp2[1][1][0]=a[n-1]+a[1];
		dp2[1][0][1]=a[n-1];
		for(int i=1;i<u;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					//if(dp2[i][j][k]==-1e18)continue;
					if(k==0){
						dp2[i+1][0][1]=max(dp2[i+1][0][1],dp2[i][j][k]);
					}
					if(j==0){
						dp2[i+1][0][k]=max(dp2[i+1][0][k],dp2[i][j][k]+a[i*2]);
					}
					if(i!=u-1)dp2[i+1][1][k]=max(dp2[i+1][1][k],dp2[i][j][k]+a[i*2+1]);
				}
			}
		}
		cout << max({dp[u][0],dp[u][1],dp2[u][0][1],dp2[u][1][1]}) << endl;
	}
}