#include <bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for( int i = l; i < r; i++ )
#define li long long int

int main() {
    int n; cin>>n;
    li a[n];
    FOR(i,0,n) cin>>a[i];
    li dp[n][n];
    FOR(i,0,n) dp[i][i] = a[i];
    FOR(j,2,n+1) {
        FOR(i,0,n) {
            int k = i+j-1;
            if( k >= n ) break;
            dp[i][k] = max(a[i]-dp[i+1][k],a[k]-dp[i][k-1]);
        }
    }
    cout<<dp[0][n-1]<<"\n";
    return 0;
}