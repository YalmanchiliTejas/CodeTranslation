#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    vector<ll> exist(M, -1);
    ll pos = N;
    ll ans = 0;
    while (exist[X] == -1 && pos >= 1) {
        exist[X] = pos;
        ans += X;
        X = (X*X)%M;
        pos--;
    }
    
    if (pos == 0) {
        cout << ans << endl;
        return 0;
    }
    
    ll periodsum = X;
    ll kari = X*X%M;
    while (kari != X) {
        periodsum += kari;
        kari = kari*kari%M;
    }
    
    
    ll period = exist[X]-pos;
    ans += (pos/period)*periodsum;
    pos %= period;
    while (pos > 0) {
        ans += X;
        X = X*X%M;
        pos--;
    }
    cout << ans << endl;
    
    return 0;
}
