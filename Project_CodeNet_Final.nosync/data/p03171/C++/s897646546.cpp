#include <bits/stdc++.h>
using namespace std;
#define lli long long int


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &it : a) cin >> it;
    
    vector<vector<lli>> dp(n,vector<lli> (n));

    for(int i = n - 1 ; i >= 0 ; --i){
        for(int j = 0 ; j < n ; ++j){
            if(i == j) dp[i][j] = a[i];
            else if(j > i){
                dp[i][j] = max(a[i]-dp[i+1][j],a[j] - dp[i][j-1]);
            }
        }
    }
    cout << dp[0][n-1] << endl;


    return 0;
}