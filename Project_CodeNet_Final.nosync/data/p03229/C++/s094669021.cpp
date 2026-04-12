#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int n; cin >> n;
    V<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(ALL(a), greater<ll>());
    int p = n - 1;
    ll pre = a[p];
    ll sum = 0;
    for(int i = 0; i < n / 2; i++){
        sum += abs(a[i] - pre);
        if(n / 2 <= p - 1) sum += abs(a[i] - a[p - 1]);
        pre = a[p];
        p--;
    }
    p = n - 1;
    pre = a[p];
    ll sum2 = 0;
    for(int i = 0; i < (n + 1) / 2; i++){
        sum2 += abs(a[i] - pre);
        if(n / 2 < p - 1) sum2 += abs(a[i] - a[p - 1]);
        pre = a[p];
        p--;
    }
    cout << max(sum, sum2) << endl;


    return 0;
}
