#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = n - 1; i >= 0; --i)


int main(){
    ll n;
    cin >> n;

    vector<ll> a(n);
    REP(i, n){
        cin >> a.at(i);
    }

    vector<ll> dp0(n + 5, 0), dp1(n + 5, 0);

    dp0.at(n - 1) = 0;
    dp1.at(n - 1) = a.at(n - 1);

    for(ll i = n - 2; i >= 0; --i){
        if((n - i) % 2 == 0){
            dp0.at(i) = a.at(i) + dp0.at(i + 2);
            dp0.at(i) = max(dp0.at(i), a.at(i + 1) + dp1.at(i + 3));
        }else{
            dp0.at(i) = a.at(i) + dp0.at(i + 2);
            dp0.at(i) = max(dp0.at(i + 1), dp0.at(i));
            dp0.at(i) = max(dp1.at(i + 2), dp0.at(i));
        }

        if((n - i) % 2 == 0){
            dp1.at(i) = a.at(i) + dp1.at(i + 2);
            dp1.at(i) = max(dp1.at(i), a.at(i + 1) + dp1.at(i + 3));
        }else{
            dp1.at(i) = a.at(i) + dp1.at(i + 2);
        }
    }
    cout << dp0.at(0) << endl;

    return 0;
}
