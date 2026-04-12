#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

const int max_n = 200000+10;
Int A[max_n];
Int dp[max_n][2][3];

int main(void) {
    int N;
    cin>>N;

    for(int i = 0;i <= N;i++) {
        for(int j = 0;j < 2;j++) {
            for(int k = 0;k < 3;k++) {
                dp[i][j][k] = -1LL<<60;
            }
        }
    }

    dp[0][1][0] = 0;
    for(int i = 0;i < N;i++) {
        cin>>A[i];
        for(int j = 0;j < 2;j++) {
            for(int k = 0;k < 3;k++) {
                if(j+k < 3) {
                    dp[i+1][1][k+j] = max(dp[i+1][1][k+j],dp[i][j][k]);
                }
                if(j == 1) {
                    dp[i+1][0][k] = max(dp[i+1][0][k],dp[i][j][k]+A[i]);
                }
            }
        }
    }

    if(N % 2 == 0) {
        cout<<max(dp[N][1][0],dp[N][0][1])<<endl;
    } else {
        cout<<max(dp[N][0][2],dp[N][1][1])<<endl;
    }

    return 0;
}
