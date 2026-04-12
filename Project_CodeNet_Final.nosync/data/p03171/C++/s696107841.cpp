#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto& v:a){
        cin >> v;
    }
    // X - Y in [i, j]
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    // length = 1
    for(int i=0; i<n; i++){
        if(1 == n%2){
            dp[i][i] = a[i];
        }
        else{
            dp[i][i] = -a[i];
        }
    }
    // length > 1
    for(int l=2; l<n+1; l++){
        for(int i=0; i<n-l+1; i++){
            // First turn (Maximize)
            if(l%2 == n%2){
                dp[i][i+l-1] = max(dp[i][i+l-2] + a[i+l-1], dp[i+1][i+l-1] + a[i]);
            }
            // Second turn (Minimize)
            else{
                dp[i][i+l-1] = min(dp[i][i+l-2] - a[i+l-1], dp[i+1][i+l-1] - a[i]);
            }
        }
    }
    // for(auto& line:dp){
    //     for(auto& v:line){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[0][n-1] << "\n";
    return 0;
}