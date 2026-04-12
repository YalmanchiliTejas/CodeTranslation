#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;


signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x : a)
        cin >> x;
    int res = 0;
    bool flag = true;
    for(int i = 0; i < n; ++i){
        if(res < i * 10)
            flag = false;
        res = max(res, i * 10 + a[i]);
    }

    res = (n - 1) * 10;
    for(int i = n - 1; i >= 0; --i){
        if(res > i * 10)
            flag = false;
        res = min(res, i * 10 - a[i]);
    }

    cout << (flag ? "yes" : "no") << endl;
}

