#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

ll dp[3010][3010];

int main(){
    int N; cin>>N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    memset(dp,0, sizeof(dp));

    for (int len = 1; len <= N; ++len) {
        for (int i = 0; i+len <= N; ++i) {
            int j=i+len;

            if((N-len)%2==0) dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]); //先手
            else dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]); //後手
        }
    }
    cout<<dp[0][N]<<endl;
    return 0;
}