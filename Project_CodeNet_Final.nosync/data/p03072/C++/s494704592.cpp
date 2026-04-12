#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
    #endif
    
    int h[101];
    int max_v = -1;
    int cnt = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        max_v = max(max_v, h[i]);
        if (h[i] >= max_v) {
            cnt++;
        }
    }
    
    cout << cnt << '\n';
    return 0;
}
