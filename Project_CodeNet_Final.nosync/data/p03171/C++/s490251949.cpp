#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int N;
	cin >> N;
	int a[N];
	for(int i=0; i<N; i++){
		cin >> a[i];
	}
	ll dp[N][N];
	for(int i=0; i<N; i++){
		dp[i][i] = a[i];
	}
	for(int i=0; i<N-1; i++){
		dp[i][i+1] = abs(a[i] - a[i+1]);
	}
	if(N % 2 == 0){
		for(int i=3; i<N; i=i+2){
			for(int j=0; j<N-i; j++){
				dp[j][j+i] = max(min(dp[j][j+i-2]+a[j+i]-a[j+i-1], dp[j+1][j+i-1]+a[j+i]-a[j]), min(dp[j+2][j+i]+a[j]-a[j+1], dp[j+1][j+i-1]+a[j]-a[j+i])); 
			}
		}
		cout << dp[0][N-1] << endl;
	}else{
		for(int i=2; i<N; i=i+2){
			for(int j=0; j<N-i; j++){
				dp[j][j+i] = max(min(dp[j][j+i-2]+a[j+i]-a[j+i-1], dp[j+1][j+i-1]+a[j+i]-a[j]), min(dp[j+2][j+i]+a[j]-a[j+1], dp[j+1][j+i-1]+a[j]-a[j+i])); 
			}
		}
		cout << dp[0][N-1] << endl;
	}
	return 0;
}