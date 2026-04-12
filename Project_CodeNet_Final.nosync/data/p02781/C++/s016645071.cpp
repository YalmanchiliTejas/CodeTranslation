#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define rep2(i, m, n) for(int i=(int)m; i<(int)n; i++)
#define ALL(a) a.begin(), a.end()
typedef long long ll;
typedef long double ld;

int binom(int64_t N, int64_t K) {
    if(K < 0 || N < K) return 0;
    int ret = 1;
    for(int i = 1; i <= K; ++i) {
        ret *= N--;
        ret /= i;
    }
    return ret;
}

int main(){
    string S; int K;
    cin >> S >> K;
    int L = S.size();

    ll ans, c = 0;
    rep(i, L){
        int x = S[i] - '0';
        if(c > K || x == 0) continue;
        ans += (x-1) * binom(L-i-1, K-c-1) * pow(9, K-c-1);
        ans += binom(L-i-1, K-c) * pow(9, K-c);
        c += (S[i] - '0' != 0);
    }
    if(c == K) ans++;
    cout << ans << endl;
}