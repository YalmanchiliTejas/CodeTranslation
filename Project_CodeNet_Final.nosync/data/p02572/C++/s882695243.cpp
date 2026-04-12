#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.141592653589793
const int N = 1000001;
using namespace std;


void f() {

}


int main() {
//    cout << fixed << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll suf[n];
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = (a[i] + suf[i + 1]) % mod;
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = (ans + a[i] * suf[i + 1]) % mod;
    }
    
    cout << ans;

}