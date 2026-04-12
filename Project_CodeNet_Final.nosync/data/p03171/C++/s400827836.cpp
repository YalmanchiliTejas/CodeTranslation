#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <utility>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;
LL MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<LL> A(N, 0);
    vector<vector<LL>> dp(N+1, vector<LL>(N+1, 0));
    for(int i=0; i<N; i++) cin >> A[i];

    LL dir = 1;
    if(N%2==0) dir = -1;
    for(int d=0; d<=N; d++, dir *= -1) {
        if(d==0) {
            for(int i=0; i<N; i++) {
                dp[i][i+1] = dir * A[i]; 

            }
            continue;
        }
        for(int i=0; i+d<=N; i++) {
            int j = i+d;
            if(dir == 1) {
                dp[i][j] = max(dp[i][j-1] + A[j-1] , dp[i+1][j] + A[i]);
            }
            if(dir == -1) {
                dp[i][j] = min(dp[i][j-1] - A[j-1] , dp[i+1][j] - A[i]);
            }
            //cout << i << " " << j << " " << dp[i][j]<< endl;
        }

    }
    cout << -dp[0][N] << endl;

    return 0;
}