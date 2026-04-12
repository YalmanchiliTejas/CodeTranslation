#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long INF = 1LL << 60;
ll MOD = 1e9+7;

int main() {

    int N; cin>>N;
    vector<ll> A(N+1,0);
    for (int i = 1; i <= N; ++i) {
        cin>>A[i];
    }

    vector<ll> B(N+1,0);
    for (int i = N-1; i >= 1; --i) {
        B[i] = (A[i+1] + B[i+1]) % MOD;
    }

    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        ans += A[i]*B[i];
        ans %= MOD;
    }

    cout<<ans<<endl;

}
