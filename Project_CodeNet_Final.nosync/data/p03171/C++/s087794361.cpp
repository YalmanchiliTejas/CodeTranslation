#include <bits/stdc++.h>
using namespace std;

long long dp[3333][3333];

int main(){
	int N;
	cin >> N;
	vector<long long> a(N);
	for(auto &i:a)cin >> i;
	
	for(int w=1;w<=N;w++){
		for(int l=0;l<=N-w;l++){
			int r=l+w-1;
			dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
		}
	}
	
	cout << dp[0][N-1] << endl;
	return 0;
}