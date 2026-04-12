#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll MOD = 1000000007;
    ll N;
    cin >> N;
    //cout << "N = " << N << endl;
    vector<ll> A(N, 0);
    vector<ll> B(N+1, 0);
    ll sum = 0;
    rep(i,N) {
        cin >> A[i];
#if 1
        B[i+1] = B[i] + A[i];
#else
        if (i != 0) {
            sum += A[i];
        }
#endif
    }

#if 1

#else
    vector<ll> Sumv(N-1, 0);
    rep(i,N-1) {
        if (i == 0) {
            Sumv[i] = sum % MOD;
        }
        else {
            Sumv[i] = (Sumv[i-1] - A[i]) % MOD;
        }
        //cout << "Sumv[" << i << "] = " << Sumv[i] << endl;
    }
#endif
    ll ans = 0;
    rep(i, N-1) {
#if 1
        ll sumt = (B[N] - B[i + 1]) % MOD;
        ans += A[i] * sumt;
#else
        ans += A[i] * Sumv[i];
#endif
        ans %= MOD;
    }
    cout << ans << endl;
 

}
