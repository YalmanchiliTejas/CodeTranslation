#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1e9+7LL;

int main() {
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);

    vector<ll> d(N);
    ll sum = 0;
    for(int i = N-1; i >= 0; --i){
        sum += A.at(i);
        d.at(i) = sum;
    }

    ll ans = 0;
    rep(i, N-1){
        ll D = d.at(i+1)%mod;
        ans += (A.at(i)*D)%mod;
        ans %= mod;
    }
    cout << ans << endl;
}