#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2,62);

int main(){
    ll mod = 1000000007;
    ll n;cin >> n;
    vec A(n);
    ll sum = 0;
    rep(i,n){
        cin >> A[i];
        if(A[i] > mod/2){
            A[i] -= mod;
        }
        sum += A[i];
        sum %= mod;
        //cout << "a" <<A[i] << endl;
    }
    sum -= A[0];
    //cout << sum << endl;
    //cout << sum << endl;
    ll ans = 0;
    for(int i = 0;i < n-1;i++){
        ans += (A[i]%mod)*sum;
        //cout << sum << endl;
        ans %= mod;
        sum = sum - A[i+1];
        sum %= mod;
    }
    if(ans < 0){
        ans += mod;
    }
    cout << ans << endl;
}