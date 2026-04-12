#include <bits/stdc++.h>
using namespace std;

long long n, dp[3004][3004], a[3004];
vector<long long> stones;

int main() {
    cin>>n;
    for(long long i = 0; i < n; i++){
        cin>>a[i];
    }
    for(long long L = n-1; L >= 0; --L){
        for(long long R = L; R < n; ++R){
            dp[L][R] = L == R ? a[L] : max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]); 
        }
    }
    cout<<dp[0][n-1];
	return 0;
}