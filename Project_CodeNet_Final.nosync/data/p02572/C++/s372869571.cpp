#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];
    ll sum = 0;

    rep(i,N){
        sum += A[i];
        sum %= MOD;
    }

    ll ans = 0;
    rep(i,N){
        sum -= A[i];
        if(sum < 0)  sum += MOD;
        ans += (A[i] * sum);
        ans %= MOD;
    }

    cout << ans << endl;
    
}
