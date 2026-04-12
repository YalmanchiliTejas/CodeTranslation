#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

ll add(ll a, ll b){
    return (a + b) % mod;
}

ll mul(ll a, ll b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return 1ll * a * b % mod;
}

ll a[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll cum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cum += a[i];
    }
    for(int i = 0; i < n; i++){
        cum -= a[i];
        ans = add(ans, mul(a[i], cum));
    }
    cout << ans;

    return 0;
}
