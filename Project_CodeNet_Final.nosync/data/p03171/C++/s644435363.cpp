#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3030][3030];

int main(){
    int N; cin >> N;

    ll a[3030];
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }

    for(int i=1; i<=N; i++){
        dp[i][i-1]=0;
    }
    for(int k=0; k<=N-1; k++){
        for(int i=1; i<=N-k; i++){
            if( (N-k)%2 ){ //太郎
                dp[i][i+k] = max (dp[i][i+k-1]+a[i+k], dp[i+1][i+k]+a[i]);
            }
            if( (N-k)%2==0 ){ //次郎
                dp[i][i+k] = min (dp[i][i+k-1]-a[i+k] ,dp[i+1][i+k]-a[i] );
            }
        }
    }
//    cout << dp[1][1] <<" " << dp[1][2] << " " << dp[2][2] << endl;
    cout << dp[1][N] << endl;
}