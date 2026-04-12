#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<ll> ALSUM(N+1);
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
        ALSUM[i+1] = ALSUM[i] + A[i];
        ALSUM[i+1]%=MOD;
    }
    ll ans = 0;
    rep(i,N){
        ll tmp = A[i]*(ALSUM[N]+MOD-ALSUM[i+1]);
        tmp %= MOD;
        ans += tmp;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}