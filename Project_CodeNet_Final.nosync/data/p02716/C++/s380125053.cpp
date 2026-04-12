#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll dp[200200][2]; // dp[i][j]:i番目のグループで(j==0:左、j==1:右)を取った時の最大値
ll dp2[200200][2][2]; // dp2[i][j][k]:i番目のグループで(j==0:左、j==1:右)を取った時の最大値
					  // kは既に1グループ飛ばしたかどうか

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<=n;i++){
		// 初期化
		dp[i][0]=dp[i][1]=-1e18;
		dp2[i][0][0]=dp2[i][0][1]=dp2[i][1][0]=dp2[i][1][1]=-1e18;
	}
	int m=n/2;
	if(n%2==0){
		dp[1][0]=a[0],dp[1][1]=a[1];
		for(int i=1;i<m;i++){
			for(int j=0;j<2;j++){
				if(j==0){
					dp[i+1][0]=max(dp[i+1][0],dp[i][j]+a[2*i]);
				}
				dp[i+1][1]=max(dp[i+1][1],dp[i][j]+a[2*i+1]);
			}
		}
		cout << max(dp[m][0],dp[m][1]) << endl;
	}
	else{
		// a[n-1]を使わない場合　上の偶数の場合と一緒
		dp[1][0]=a[0],dp[1][1]=a[1];
		for(int i=1;i<m;i++){
			for(int j=0;j<2;j++){
				if(j==0){
					dp[i+1][0]=max(dp[i+1][0],dp[i][j]+a[2*i]);
				}
				dp[i+1][1]=max(dp[i+1][1],dp[i][j]+a[2*i+1]);
			}
		}
		// a[n-1]を使う場合
		dp2[1][0][0]=a[n-1]+a[0],dp2[1][1][0]=a[n-1]+a[1];
		dp2[1][0][1]=a[n-1];
		for(int i=1;i<m;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					if(k==0){
						dp2[i+1][0][1]=max(dp2[i+1][0][1],dp2[i][j][k]);
					}
					if(j==0){
						dp2[i+1][0][k]=max(dp2[i+1][0][k],dp2[i][j][k]+a[i*2]);
					}
					// a[n-2]は使えない事に注意！
					if(i!=m-1)dp2[i+1][1][k]=max(dp2[i+1][1][k],dp2[i][j][k]+a[i*2+1]);
				}
			}
		}
		cout << max({dp[m][0],dp[m][1],dp2[m][0][1],dp2[m][1][1]}) << endl;
	}
}
