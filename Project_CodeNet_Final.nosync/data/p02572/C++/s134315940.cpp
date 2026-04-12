#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

ll moddividing(ll x,ll y){
    vector<ll> vec(30);
    rep(i,30){
        vec[i] = y;
        y = y * y % 1000000007;
    }
    ll c = x;
    c = c * vec[0] % 1000000007;
    c = c * vec[2] % 1000000007;
    c = c * vec[9] % 1000000007;
    c = c * vec[11] % 1000000007;
    c = c * vec[14] % 1000000007;
    c = c * vec[15] % 1000000007;
    c = c * vec[17] % 1000000007;
    c = c * vec[19] % 1000000007;
    c = c * vec[20] % 1000000007;
    c = c * vec[23] % 1000000007;
    c = c * vec[24] % 1000000007;
    c = c * vec[25] % 1000000007;
    c = c * vec[27] % 1000000007;
    c = c * vec[28] % 1000000007;
    c = c * vec[29] % 1000000007;
    return c;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    ll all_sum = 0;
    ll square_sum = 0;
    rep(i,N){
        all_sum = (all_sum + A[i]) % 1000000007;
    }
    rep(i,N){
        square_sum = (square_sum + (A[i] * A[i]) % 1000000007) % 1000000007;
    }
    all_sum = (all_sum * all_sum) % 1000000007;
    ll ans = (all_sum + 1000000007 - square_sum) % 1000000007;
    ll y = 2;
    cout << moddividing(ans, y) << endl;
}