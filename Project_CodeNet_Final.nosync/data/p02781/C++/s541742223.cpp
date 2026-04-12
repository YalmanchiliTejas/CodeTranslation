#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

typedef pair<ll, ll> P;
#define fs first
#define sc second

ll dp[101][2][4];

int main(){
    string N;
    cin >> N;
    int K;
    cin >> K;

    dp[0][1][0] = 1;
    for(int i = 0; i < (int)N.size(); i++){
        int n = N[i] - '0';

        dp[i + 1][0][0] = 1;
        dp[i + 1][1][0] = 0;

        if(n != 0){
            dp[i + 1][1][1] = dp[i][1][0];
            dp[i + 1][1][2] = dp[i][1][1];
            dp[i + 1][1][3] = dp[i][1][2];

            dp[i + 1][0][1] = dp[i][1][1] + dp[i][0][1] + 9 * dp[i][0][0] + (n - 1) * dp[i][1][0];
            dp[i + 1][0][2] = dp[i][1][2] + dp[i][0][2] + 9 * dp[i][0][1] + (n - 1) * dp[i][1][1];
            dp[i + 1][0][3] = dp[i][1][3] + dp[i][0][3] + 9 * dp[i][0][2] + (n - 1) * dp[i][1][2];
        }
        else {
            //n == 0
            dp[i + 1][1][1] = dp[i][1][1];
            dp[i + 1][1][2] = dp[i][1][2];
            dp[i + 1][1][3] = dp[i][1][3];

            dp[i + 1][0][1] = dp[i][0][1] + 9 * dp[i][0][0];
            dp[i + 1][0][2] = dp[i][0][2] + 9 * dp[i][0][1];
            dp[i + 1][0][3] = dp[i][0][3] + 9 * dp[i][0][2];
        }
    }



    cout << dp[(int)N.size()][1][K] + dp[(int)N.size()][0][K] << endl;
    return 0;
}
