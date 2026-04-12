#include <bits/stdc++.h>
#define int long long
using namespace std;

string N; int K;

int dp[1000][2][10];

signed main(){
	cin>>N>>K;
	dp[0][0][0]=1;
	int l=N.size();
	for(int i=0;i<l;i++){
		for(int smaller=0;smaller<2;smaller++){
			//smallerが1ならi桁目まではNと一緒
			//0ならNよりも小さいことが確定している
			for(int j=0;j<=K;j++){
				for(int k=0; k<=(smaller ? 9 : N[i]-'0'); k++){
					dp[i+1][smaller or (k<(N[i]-'0'))][k==0 ? j : j+1]+=dp[i][smaller][j];
				}
			}
		}
	}

	cout<<dp[l][0][K]+dp[l][1][K]<<endl;
}