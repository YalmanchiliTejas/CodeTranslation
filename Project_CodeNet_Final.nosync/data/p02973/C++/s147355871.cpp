#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long



int32_t main() {

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> cur;

    for(int i = 0; i < n; ++i) {
        int ai = a[i];
        auto it = lower_bound(cur.begin(), cur.end(), ai);
        
        if(it == cur.end() || *it >= ai) {
            if(it == cur.begin()) {
                cur.insert(cur.begin(), ai);
                continue;
            } else {
                it--;
            }
        }

        *it = ai;
    }

    cout << cur.size() << endl;
    
    return 0;
}
