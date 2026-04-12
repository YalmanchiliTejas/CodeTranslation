#include <bits/stdc++.h>
using namespace std;


using LL = long long int;
using uLL = unsigned long long int;
using uint = unsigned int;
using ld = long double;

const int N = 3007;

LL dp[N][N][2];
int A[N];
//dp[l][r][0] = max(dp[l+1][r][1]+A[l], dp[l][r-1][1]+A[r])
//dp[l][r][1] = min(dp[l+1][r][0], dp[l][r-1][0])

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    LL sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        sum += A[i];
    }
    for(int d = 0; d < n; d++){
        for(int i = 1; i <= n-d; i++){
            //cout << "L R " << i << " " << i+d << '\n';
            dp[i][i+d][0] = max(dp[i+1][i+d][1]+A[i], dp[i][i+d-1][1]+A[i+d]);
            dp[i][i+d][1] = min(dp[i+1][i+d][0], dp[i][i+d-1][0]);
            //cout << dp[i][i+d][0] << " " << dp[i][i+d][1] << '\n';
        }
    }
    LL x = dp[1][n][0];
    LL y = sum-x;
    cout << x-y << '\n';
    
    
    
    return 0;
}