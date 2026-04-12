#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 3e3;
ll dp[MAX_N + 1][MAX_N+1] = {0}; // dp[i][j] := iターン目に残ってる数列の左端がjの時の場合の数
bool used[MAX_N+1][MAX_N+1] = {0};
int N;
vector<ll> a;

ll rec(int k, int l, int r){ //手番がk番目で残ってる数列の左端、右端の座標
    if(k == N) return dp[k][l] = pow(-1, k + 1) * a[l];
    if(used[k][l]) return dp[k][l];

    used[k][l] = 1;

    if(k % 2 == 1) return dp[k][l] = max(rec(k+1, l, r-1) + a[r], rec(k+1, l+1, r) + a[l]);
    else return dp[k][l] = min(rec(k+1, l+1, r) - a[l] , rec(k+1, l, r - 1) - a[r]);

    return 0;
}

int main(){
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++ ) cin >> a[i];

    cout << rec(1, 0, N - 1) << endl;

    /* for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cout  << i << " " << j << dp[i][j] << endl;
        }
    } */

}