#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 3;

int n,a[N];

long long dp[N][N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];	
    }
    for(int l = n; l >= 1; l--){
    	for(int r = l; r <= n; r++){
    		if(l == r)
    			dp[l][r] = a[l];
    		else
    			dp[l][r] = max(a[l] - dp[l + 1][r],a[r] - dp[l][r - 1]);
    	}
    }
    cout << dp[1][n];
	return 0;
}