#include<bits/stdc++.h>
using namespace std;

const int mod = 1000*1000*1000+7;

int po(int x, int n) {
    int ret = 1;
    while(n) {
        if(n & 1) ret = 1LL*ret*x%mod;
        x = 1LL*x*x%mod;
        n /= 2;
    }
    return ret;
}
int inv(int x) { return po(x, mod - 2); }

vector<vector<int> > comb;
vector<int> fact, invf;

int N, A, B, C, D;

int cc[1010][1010];
int dp(int a, int rem) {
    int &ret = cc[a][rem];
    if(ret != -1) return ret;

    if(a == B + 1) return ret = rem == 0;

    ret = dp(a + 1, rem);
    int tmp = rem;
    int mul = 1;

    for(int i = 1; a*i <= rem; i++) {
        mul = 1LL*mul*comb[tmp][a]%mod;
        if(C <= i && i <= D) {
            ret += 1LL*mul*invf[i]%mod*dp(a + 1, tmp - a)%mod;
            ret %= mod;
        }
        tmp -= a;
    }
    return ret;
}

int main() {
    cin>>N>>A>>B>>C>>D;

    comb = vector<vector<int> >(N+1, vector<int>(N+1, 0));
    comb[0][0] = 1;
    for(int i = 1; i <= N; i++) {
        comb[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
        }
    }
    fact.resize(N + 1);
    fact[0] = 1;
    for(int i = 1; i <= N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    invf.resize(N + 1);
    for(int i = 0; i <= N; i++) {
        invf[i] = inv(fact[i]);
    }

    memset(cc, -1, sizeof(cc));
    printf("%d", dp(A, N));
}
