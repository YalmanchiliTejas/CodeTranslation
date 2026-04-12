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
    for(int i=0; i<N; i++) if(A[i] == S) add(ans, (i+1)*(N-i));

    auto rec = [&](auto&& rec, int L, int R)->void{
        if(R-L < 2) return;
        int M = (L+R)/2;

        vector<int64_t> VL(3001), VR(3001), dp(3001);
        dp[0] = 1;
        for(int i=M-1; i>=L; i--){
            for(int j=A[i]; j<S; j++) add(VL[j], dp[j-A[i]]*(i+1));
            for(int j=3000; j>=A[i]; j--) add(dp[j], dp[j-A[i]]);
        }
        fill(dp.begin(), dp.end(), 0);
        dp[0] = 1;
        for(int i=M; i<R; i++){
            for(int j=A[i]; j<S; j++) add(VR[j], dp[j-A[i]]*(N-i));
            for(int j=3000; j>=A[i]; j--) add(dp[j], dp[j-A[i]]);
        }
        for(int j=1; j<S; j++)  add(ans, VL[j] * VR[S-j]);

        rec(rec, L, M);
        rec(rec, M, R);
    };

    rec(rec, 0, N);
    cout << ans << endl;
    return 0;
}
