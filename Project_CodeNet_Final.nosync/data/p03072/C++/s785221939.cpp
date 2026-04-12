#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

int main() {
    int n; cin >> n;
    vector<int> h(n); rep(i, n) cin >> h[i];
    int cnt = 0, ch = h[0];
    rep(i, n){
        if(ch <= h[i]) cnt++;
        ch = max(ch, h[i]);
    }
    cout << cnt << endl;
    return 0;
}
