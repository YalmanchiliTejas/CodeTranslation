#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

vector<ll> a, p; // a は層の厚さ。p はパティの数

ll f(int n, ll x){
    if(n == 0){
        return 1;
    }
    else if(x == 1){
        return 0;
    }
    else if(x <= a[n-1] + 1){
        return f(n-1, x-1);
    }
    else if(x == a[n-1] + 2){
        return p[n-1] + 1;
    }
    else if(x <= 2 * a[n-1] + 2){
        return p[n-1] + 1 + f(n-1, x-(a[n-1] + 2));
    }
    else{
        return p[n-1] * 2 + 1;
    }
}

int main() {

    int n;
    ll x;
    cin >> n >> x;

    a.push_back(1); //レベル0
    p.push_back(1); //レベル0
    for(int i=1; i<=n; ++i){
        a.push_back(a.back() * 2 + 3);
        p.push_back(p.back() * 2 + 1);
    }

    ll ans = f(n, x);

    cout << ans << endl;

    return 0;
}