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

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, ll> P;


int main(){
    string s;   cin >> s;
    int k; cin >> k;

    vector<vector<vector<ll>>> dp(s.size(), vector<vector<ll>>(k+1, vector<ll>(2, 0LL)));
    dp[0][0][0] = 1;
    dp[0][1][0] = s[0] - '0' - 1;
    dp[0][1][1] = 1;
    for(int i = 1; i < s.size(); i++){
        for(int j = 0; j <= k; j++){
            if(s[i] - '0' == 0){
                dp[i][j][1] += dp[i-1][j][1];
                dp[i][j][0] += dp[i-1][j][0];
                if(j+1 <= k){
                    dp[i][j+1][0] += dp[i-1][j][0] * 9;
                }
            }
            else{
                if(j+1 <= k){
                    dp[i][j+1][1] += dp[i-1][j][1];
                    dp[i][j+1][0] += (s[i] - '0' - 1) * dp[i-1][j][1];
                    dp[i][j+1][0] += 9 * dp[i-1][j][0];
                }
                dp[i][j][0] += dp[i-1][j][0];
                dp[i][j][0] += dp[i-1][j][1];
            }
//            cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    }


    cout << dp[s.size()-1][k][0] + dp[s.size()-1][k][1] << endl;

    return 0;
}
