/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define maxN 1000000

int32_t main()
{
    fastio;
    
    int n; cin >> n;
    vector<int> a(n); for(auto &x: a) cin >> x;

    int dp[n][n];
    for(int L=n-1; L>=0; L--){
        for(int R=L; R<n; R++){
            if(L == R) dp[L][R] = a[L];
            else dp[L][R] = max(a[L]-dp[L+1][R], a[R]-dp[L][R-1]);
        }
    }

    cout << dp[0][n-1] << endl;
    
    return 0;   
}
    
