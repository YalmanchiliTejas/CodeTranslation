#include<bits/stdc++.h>

using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const long long INF = 1LL<<60;
const int MOD = 1000000007;
int n;
ll a[3010];
ll dp[3010][3010]={0};

int main() {
    cin >> n; 
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = n-1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if((n-i-j-1)%2==0){
                dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1] + a[j]);
            }else{
                dp[i][j] = min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
            }
        }
    }

cout << dp[0][n-1];

return 0;
}


