#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main(){
    int N, S;
    while(cin >> N >> S){
        vector<int> A(N);
        for(auto& t : A) cin >> t;
        vector<long long> dp(S, 0);
        long long res = 0;
        // dp[i] = 部分列の和がiとなるL=1~Nの時の場合の数
        for(int i=0;i<N;i++){
            for(int j=S-1;j>0;j--){
                if(j+A[i] == S){
                    res += dp[j] * (N-i); // Rはi以降
                    res %= MOD;
                } else if(j+A[i] < S){
                    dp[j+A[i]] += dp[j]; // j+A[i]はjにA[i]を足しただけだからjの場合の数を含む
                    dp[j+A[i]] %= MOD;
                }
            }
            if(A[i] == S){
                res += (i+1) * (N-i); // L=1~i+1 R=i+1~N
                res %= MOD;
            } else if(A[i] < S){
                dp[A[i]] += (i+1); // L=1~iまでの分
                dp[A[i]] %= MOD;
            }
        }
        cout << res << endl;
    }
}
