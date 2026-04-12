#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>
#include <numeric>
#include <string.h>
#include <sys/time.h>
#include <random>


#define fs first
#define sc second
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, ll> P;


int main(){
    int n;  cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> s(n, 0);
    s[0] = a[0];   s[1] = a[1];
    for(int i = 2; i < n; i++){
        s[i] += s[i-2] + a[i];
    }

    if(n % 2 == 0){
        vector<vector<ll>> dp(n, vector<ll>(2, LONG_LONG_MIN / 3));
        dp[0][0] = a[0];
        dp[1][1] = a[1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                if(j == 0){
                    if(i + 2 < n) dp[i+2][0] = max(dp[i+2][0], dp[i][j] + a[i+2]);
                    if(i + 3 < n) dp[i+3][1] = max(dp[i+3][1], dp[i][j] + a[i+3]);
                }
                if(j == 1){
                    if(i + 2 < n) dp[i+2][1] = max(dp[i+2][1], dp[i][j] + a[i+2]);
                }
            }
        }

        cout << max(dp[n-2][0], dp[n-1][1]) << endl;
        return 0;
    }

    vector<vector<ll>> dp(n, vector<ll>(3, LONG_LONG_MIN / 3));
    dp[0][0] = a[0];
    dp[1][1] = a[1];
    dp[2][2] = a[2];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){
                if(i + 2 < n) dp[i+2][0] = max(dp[i+2][0], dp[i][j] + a[i+2]);
                if(i + 3 < n) dp[i+3][1] = max(dp[i+3][1], dp[i][j] + a[i+3]);
                if(i + 4 < n) dp[i+4][2] = max(dp[i+4][2], dp[i][j] + a[i+4]);
            }
            if(j == 1){
                if(i + 2 < n) dp[i+2][1] = max(dp[i+2][1], dp[i][j] + a[i+2]);
                if(i + 3 < n) dp[i+3][2] = max(dp[i+3][2], dp[i][j] + a[i+3]);
            }
            if(j == 2){
                if(i + 2 < n)   dp[i+2][2] = max(dp[i+2][2], dp[i][j] + a[i+2]);
            }
        }
    }

    cout << max(dp[n-3][0], max(dp[n-2][1], dp[n-1][2])) << endl;


    return 0;
}
