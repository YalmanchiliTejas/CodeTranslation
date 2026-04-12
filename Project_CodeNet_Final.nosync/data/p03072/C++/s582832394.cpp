#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

template<class t>
inline bool chmax(t &a, t b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class t>
inline bool chmin(t &a, t b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int max_h = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] >= max_h) {
            ans++;
            max_h = h[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}
