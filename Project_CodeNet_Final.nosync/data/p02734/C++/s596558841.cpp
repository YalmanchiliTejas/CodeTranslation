#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; (i) < (n); (i)++)
using namespace std;
using Graph = vector<vector<int>>;
using P = pair<long, long>;

long modpow(long a, long n, long mod) {
    long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long modinv(long a, long mod) {
    return modpow(a, mod - 2, mod);
}

struct compare1 { 
    bool operator()(const pair<long, long>& value,  
                                const long& key) 
    { 
        return (value.first < key); 
    } 
    bool operator()(const long& key,  
                    const pair<long, long>& value) 
    { 
        return (key < value.first); 
    } 
}; 

int main()
{
    int N, S; cin >> N >> S;
    int A[4000];
    REP(i, N) cin >> A[i];
    long mod = 998244353;
    long dp1[4000], dp2[4000];
    long ans = 0;
    REP(i, S+1) dp1[i] = 0;
    REP(i, N){
        dp2[0] = 0;
        for(int j = 1; j <= S; j++){
            if(j < A[i]) dp2[j] = dp1[j];
            else if(j == A[i]){
                dp2[j] = dp1[j] + i + 1;
                dp2[j] %= mod;
            }else{
                dp2[j] = dp1[j] + dp1[j - A[i]];
                dp2[j] %= mod;
            }
        }
        ans += dp2[S] * ((long)N - (long)i);
        ans %= mod;
        REP(i, S) dp1[i] = dp2[i];
        dp1[S] = 0;
    }
    cout << ans << endl;
    return 0;
}

