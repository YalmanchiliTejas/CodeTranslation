#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

i64 dp[3003][3003]={0};

int main(){
    int n;
    cin >> n;
    vector<i64> v;
    for(int i=0;i<n;++i){
        i64 a;
        cin >> a;
        v.push_back(a);
    }

    for(int i=1;i<=n;++i){
        for(int j=0;j<=n-i;++j){
            if((n-i)%2 == 0){
                dp[j][j+i] = max(v[j]+dp[j+1][j+i], v[j+i-1]+dp[j][j+i-1]);
            }else{
                dp[j][j+i] = min(-v[j]+dp[j+1][j+i], -v[j+i-1]+dp[j][j+i-1]);
            }
        }
    }

    cout << dp[0][n] << endl;

    return 0;
}
