#include<bits/stdc++.h>
using namespace std;
int n ;
const int mxN=3002,M=1e9+7;

long long k,a[mxN+1];

//long long dp[mxN][mxN];
int main(){
	cin >> n  ;
    for(int i = 0 ; i< n  ; ++i){
        cin >> a[i];
    }

    vector< vector<long long> > dp(n,vector<long long>(n,0));
    
    for(int i = n-1 ; i>=0 ; --i){
        for(int j=i; j<=n-1 ; j++){
            if(i==j)
            dp[i][j] = a[i];
            else
            dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }

    cout << dp[0][n-1];
}