#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18
ll mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n+1, 0);
    rep(i, n) {
        cin >> a[i];
        b[i+1] = b[i] + a[i];
    }

    ll ans = 0;

    rep(i, n) {
       ll sum = (b[n] - b[i+1]) % mod;

       ans += a[i] * sum;
       ans%= mod; 
    }

    cout << ans << endl;

    return 0;
}