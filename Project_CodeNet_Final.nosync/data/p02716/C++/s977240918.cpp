#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

ll dp[200010][2][3] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vec<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    ll inf = 1e18;
    for(int i=0;i<=N;i++) for(int j=0;j<2;j++) for(int k=0;k<3;k++) dp[i][j][k] = -inf;
    dp[0][0][0] = 0;
    for(int i=0;i<N;i++){
        //選ぶ
        for(int k=0;k<3;k++){
            dp[i+1][1][k] = max(dp[i+1][1][k],dp[i][0][k]+A[i]);
        }
        //選ばない
        if(i!=0){
            for(int k=0;k<3;k++){
                dp[i+1][0][k] = max(dp[i+1][0][k],dp[i][1][k]);
            }
            for(int k=0;k<2;k++) dp[i+1][0][k+1] = max(dp[i+1][0][k+1],dp[i][0][k]);
        }else {
            dp[i+1][0][1] = 0;
        }
    }
    ll ans = -inf;
    if(N%2==1) ans = max(dp[N][1][2],dp[N][0][1]);
    else ans = max(dp[N][1][1],dp[N][0][0]);
    cout << ans << "\n";
}
