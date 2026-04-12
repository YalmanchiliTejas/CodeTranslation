#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <list>
#include <queue>
using namespace std;

#define int long long
#define INF 1e18

signed main() {
    int n; cin >> n;
    vector<int> h(n); for(int i = 0; i < n; i++) cin >> h[i];

    int ans = 1;
    for(int i = 1; i < n; i++) {
        bool flag = true;
        for(int j = 0; j < i; j++) {
            if(h[i] < h[j]) flag = false;
        }
        if(flag) ans++;
    }

    cout << ans << endl;
}
