#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> da(n);
    for(int i=0;i<n;i++){
        cin >> da[i];
    }
    vector<vector<long long>> dp(n,vector<long long> (n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=da[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            dp[j][i+j+1]=max(da[j]-dp[j+1][i+j+1],da[i+j+1]-dp[j][i+j]);
        }
    }
    cout << dp[0][n-1] << endl;
}
