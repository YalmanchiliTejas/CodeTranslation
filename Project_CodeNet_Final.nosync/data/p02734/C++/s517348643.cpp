#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
using lint = long long int;
template<typename T> void modAdd(T& a, T b, T mod) { a = (a + b) % mod; }

const lint MOD = 998244353;

int N, S, A[3003];
lint dp[3003][3003];

int main() {
    cin >> N >> S;
    for_(i,0,N) cin >> A[i];

    for_(i,0,N+1) for_(j,0,S+1) dp[i][j] = 0;
    for_(i,0,N) dp[i][0] = 1;

    for_(i,0,N) for_(j,0,S+1) {
        modAdd(dp[i+1][j], dp[i][j], MOD);
        int jj = j + A[i];
        if (jj <= S) modAdd(dp[i+1][jj], dp[i][j], MOD);
    }

    lint ans = 0;
    for_(i,0,N+1) modAdd(ans, dp[i][S], MOD);
    cout << ans << endl;
}