#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n;
	cin>>n;
	vector<long long int>a(n);
	for(long long int i = 0 ; i < n ; i++) cin>>a[i];
    long long int dp[n][n];
    for(int i = 0 ; i < n ; i++){
        for(long long int j = 0 ; j < n ; j++){
            dp[i][j] = 0;
        }
    }
    for(long long int i = 0 ; i < n ; i++){
        dp[i][i] = a[i];
    }
    for (long long int size = 1 ; size < n ; size++){
        long long int i = 0;
        long long int j = i+size;
        while(j < n){
            dp[i][j] = max(a[i] - dp[i+1][j],a[j] - dp[i][j-1]);
            i++;j++;
        }
    }
    cout<<dp[0][n-1]<<endl;
	return 0;
}
