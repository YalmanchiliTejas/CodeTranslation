#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;  cin >> n;
    vector<int>a(n);
    rep(i, n)   cin >> a[i];
    vector<vector<ll> >dp(n+1, vector<ll>(n+1));  //dp[i][j] := [i,j)
    for(int k = 1; k <= n; k++){
        for(int l = 0; l <= n-k; l++){
            int i = l;
            int j = k + l;
            if((n-(j-i)+1) % 2 == 1){
                dp[i][j] = max(dp[i][j-1] + a[j-1], dp[i+1][j] + a[i]);
            }else{
                dp[i][j] = min(dp[i][j-1] - a[j-1], dp[i+1][j] - a[i]);
            }
        }
    }
    cout << dp[0][n] << endl;
}
