#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)

int main() {
    int n; cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    vector<int> h_max(n);
    rep(i,n){
        if(i == 0) h_max[i] = h[i];
        h_max[i] = max(h[i],h_max[i-1]);
    }

    int ans =0;
    rep(i,n){
        if(h_max[i] == h[i]) ans++;
    }
    cout << ans << endl;
}
