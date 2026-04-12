#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    vector<int> V(N), dp(N, -1);
    rep(i,0,N)cin >> V[i];
    rep(i,0,N){
        auto itr = lower_bound(dp.rbegin(), dp.rend(), V[i]);
        itr--;
        //cout << distance(dp.rbegin(), itr) << endl;
        *itr = V[i];
    }
    //rep(i,0,N)cout << dp[i] << endl;
    for(int i = N-1;i >= 0;i--){
        if(dp[i] != -1){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << N << endl;
}