#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using P = pair<int, int>;
static const int mod = 1000000007;

int main(){
    int n;
    cin >> n;

    ll A[1000000];
    ll sum = 0;

    ll ans = 0;

    rep(i, n){
        cin >> A[i];
        sum += A[i];
        sum %= mod;
    }

    for (int i = 0; i < n; i++){
        sum -= A[i];

        if (sum < 0){
            sum += mod;
        }
        ans += A[i] * sum;
        ans %= mod;
    }

    cout << ans << endl;



    return 0;
}