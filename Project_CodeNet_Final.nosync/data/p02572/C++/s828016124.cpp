#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 200000;
const int MOD = 1000000007;

int N;
int A[MAX_N];
ll B[MAX_N + 1];

void solve();

int main(){

    B[0] = 0;
    cin >> N;
    for(int i=0; i<N ; i++){
       cin >> A[i];
       B[i + 1] = B[i] + A[i]; 
    }

    solve();

    return 0;
}

void solve(){

    long ans = 0;

    // iについて全探索する
    for(int i=0; i<N; i++){
        //累積和を使って A[i+1] + ... + A[N] を求める
        ll sum = (B[N] - B[i+1]) % MOD;

        ans += A[i] * sum;
        ans %= MOD;
    }

    cout << ans << endl;
}