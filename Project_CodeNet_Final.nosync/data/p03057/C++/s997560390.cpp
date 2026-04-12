#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

template<typename T>
struct BIT {
    int n;
    vector<T> dat;

    BIT(int n=0){
        initialize(n);
    }

    void initialize(int nin){
        n = nin;
        dat.resize(n);
        for(int i = 0; i<n; i++) dat[i] = 0;
    }

    T sum(int i){
        T s = 0;
        while(i >= 0){
            add(s, dat[i]);
            i = (i & (i+1)) - 1;
        }
        return s;
    }

    T sum_between(int i, int j){
        int64_t res = sum(j);
        if(i>0) add(res, MOD - sum(i-1));
        return res;
    }

    void plus(int i, T x){
        while(i < n){
            add(dat[i], x);
            i |= i+1;
        }
    }

    // a[0]+...+a[ret] >= x
    int lower_bound(T x){
        int ret = -1;
        int k = 1;
        while(2*k <= n) k <<= 1;
        for( ;k>0; k>>=1){
            if(ret+k < n && dat[ret+k] < x){
                x -= dat[ret+k];
                ret += k;
            }
        }
        return ret + 1;
    }
};

void solve1(int N){
    static int64_t dp[200001][2][2] = {0};
    dp[0][0][0] = dp[0][1][1] = 1;
    for(int i=0; i<N-1; i++){
        for(int j=0; j<2; j++){
            add(dp[i+1][0][j], dp[i][0][j] + dp[i][1][j]);
            add(dp[i+1][1][j], dp[i][0][j]);
        }
    }
    int64_t ans = (dp[N-1][0][0] + dp[N-1][1][0] + dp[N-1][0][1]) % MOD;
    cout << ans << endl;
    exit(0);
}

int main(){
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    if(S[0] == 'B'){
        for(int i=0; i<M; i++) S[i] = (S[i] == 'B' ? 'R' : 'B');
    }

    int len = 0, first = -1, lim = N;
    for(int i=0; i<M; i++){
        if(S[i] == 'R'){
            len++;
        }else if(len > 0){
            if(first == -1){
                first = len;
            }else{
                if(len%2) lim = min(lim, len+1);
            }
            len = 0;
        }
    }
    if(len == M){
        solve1(N);
    }
    if(N%2){
        cout << 0 << endl;
        return 0;
    }
    lim = min(lim, (first/2+1)*2);

    BIT<int64_t> bit(N+1);
    bit.plus(0, 1);
    for(int i=2; i<=N; i+=2){
        int l = max(0, i-lim);
        int64_t res = bit.sum_between(l, i-1);
        bit.plus(i, res);
    }

    int64_t ans = 0;
    for(int i=1; i<=min(N-1, lim-1); i+=2){
        add(ans, (i+1) * bit.sum_between(N-i-1, N-i-1) % MOD);
    }
    cout << ans << endl;
    return 0;
}
