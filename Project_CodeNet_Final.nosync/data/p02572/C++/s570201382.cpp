#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define For(i, a, n) for(long long i = a; (a < n) ? (i < n) : (i > n); (a < n) ? (i++) : (i--))
#define mod 1000000007
#define pb push_back
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;


void solve() {
    ll n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    For(i, 0, n) {
        cin >> a[i];
        sum = (sum % mod + a[i] % mod) % mod;
    }
    ll v = 0;
    ll ans = 0;
    For(i ,0 , n - 1) {
        v = (v % mod + a[i] % mod) % mod;
        ll z = sum - v;
        if(z < 0)
            z = (z + mod) % mod;
        ans = (ans % mod + (z * (a[i] % mod) % mod) % mod) % mod;
    }
    cout << ans << "\n";
}

int main() {
    fio;
    solve();
}