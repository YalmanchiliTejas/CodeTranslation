#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    int ans = 0;
    int highest = 0;
    rep(i, n) {
        cin >> h[i];
        if(h[i] >= highest) ans++;
        highest = max(h[i], highest);
    }
    cout << ans << endl;
}