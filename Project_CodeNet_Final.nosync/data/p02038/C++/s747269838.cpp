#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    // B shibh308
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x : a){
        char c;
        cin >> c;
        x = (c == 'T');
    }
    function<bool(bool,bool)> f = [&](bool x, bool y){
        return (!x) | y;
    };
    bool fl = a[0];
    for(int i = 1; i < n; ++i){
        fl = f(fl, a[i]);
    }
    cout << (fl ? "T" : "F") << endl;
}

