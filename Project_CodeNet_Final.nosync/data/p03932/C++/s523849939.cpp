#include <iostream>
using namespace std;

int a[410][210], dp[410][210][210];

int main() {
	int H, W;
	cin >> H >> W;
	if(H==1 || W==1){
		int sum=0;
		for(int i=0; i<max(H, W); ++i){
			int b;
			cin >> b;
			sum += b;
		}
		cout << sum << endl;
		return 0;
	}
	for(int i=0; i<H; ++i){
		for(int j=0; j<W; ++j){
			cin >> a[i+j][j];
		}
	}
	int ans=a[0][0]+a[H+W-2][W-1];
	dp[1][0][1]=a[1][0]+a[1][1];
	for(int i=1; i<H+W-3; ++i){
		for(int p=0; p<W; ++p){
			for(int q=p+1; q<W; ++q){
				dp[i+1][p][q]=max(dp[i+1][p][q], dp[i][p][q]+a[i+1][p]+a[i+1][q]);
				dp[i+1][p][q+1]=max(dp[i+1][p][q+1], dp[i][p][q]+a[i+1][p]+a[i+1][q+1]);
				dp[i+1][p+1][q+1]=max(dp[i+1][p+1][q+1], dp[i][p][q]+a[i+1][p+1]+a[i+1][q+1]);
				if(p+1<q){
					dp[i+1][p+1][q]=max(dp[i+1][p+1][q], dp[i][p][q]+a[i+1][p+1]+a[i+1][q]);
				}
			}
		}
	}
	cout << ans+dp[H+W-3][W-2][W-1] << endl;
	return 0;
}