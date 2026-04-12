#include <iostream>
#include <vector>

using namespace std;

#define LL long long

int main() {
    // freopen("a.txt", "r", stdin);
    int mod = 998244353;
    int N, S, res = 0;
    cin >> N >> S;

    vector<int> A(N + 1, 0);
    for(int i = 1; i <= N; ++i) cin >> A[i];

    vector<int > dp(S+1, 0);
    for(int i = 1; i <= N; ++i) {
        if(S == A[i]) res = (res + 1ll * i * (N - i + 1) % mod) % mod;
        else if(S > A[i]) res = (res + 1ll * dp[S - A[i]] * (N - i + 1) % mod) % mod;
        for(int j = S; j >= A[i]; --j)
            dp[j] = (dp[j] + dp[j - A[i]] + (j == A[i]? i: 0)) % mod;
    }

    cout << res << endl;
    return 0;
}