#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
#define rep(i,n) for(auto i=0;i<(n);i++)

using namespace std;


int main() {
    ll n;
    cin >> n;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];

    vector<ll> y(n);
    rep(i, n) y[i] = x[i];
    sort(y.begin(), y.end());

    ll left = y[n/2 - 1];
    ll right = y[n/2];

    if(left == right){
        rep(i, n) cout << left << endl;
        return 0;
    }

    rep(i, n){
        if(x[i] <= left) cout << right << endl;
        else             cout << left << endl;
    }



    
    return 0;
}