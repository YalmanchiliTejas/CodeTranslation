#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long



int32_t main() {
    
    int n; cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i) cin >> h[i];

    int ans = 0, cur = 0;

    for(int i = 0; i < n; ++i) {
        if(h[i] >= cur) {
            ++ans;
            cur = h[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}
