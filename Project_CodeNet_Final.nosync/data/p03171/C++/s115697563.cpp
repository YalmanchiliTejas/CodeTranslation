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

Int dp[3001][3001];
int N;

int main(void) {
    cin>>N;
    vector<Int> A(N);
    
    for(int i = 0;i < N;i++) {
        cin>>A[i];
    }

    for(int len = 1;len <= N;len++) {
        for(int i = 0;i + len <= N;i++) {
            int j = i+len;
            
            if((N - len) % 2 == 0)
                dp[i][j] = max(dp[i+1][j]+A[i],dp[i][j-1]+A[j-1]);
            else
                dp[i][j] = min(dp[i+1][j]-A[i],dp[i][j-1]-A[j-1]);
        }
    }

    cout<<dp[0][N]<<endl;

    return 0;
}

