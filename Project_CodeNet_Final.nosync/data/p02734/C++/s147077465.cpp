#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 998244353;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

int main(){
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    int64_t ans = 0;
    static int64_t dp[3001];
    for(int i=0; i<N; i++){
        for(int j=3000; j>A[i]; j--) add(dp[j], dp[j-A[i]]);
        add(dp[A[i]], i+1);
        add(ans, dp[S]);
    }
    cout << ans << endl;
    return 0;
}
