#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;

const ll NMAX = 2010;
using namespace std;

ll dp[3005][3005];

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 0; j++){
            dp[i][j] = 0;
        }
    }

    for(int l = 1; l <= n; l++){
        for(int i = 0; i <= n-l; i++){
            int j = i+l;
            if((n-l)%2==0){
                dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
            } else {
                dp[i][j] = min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
            }
        }
    }

    cout << dp[0][n] << endl;

    return 0;
}