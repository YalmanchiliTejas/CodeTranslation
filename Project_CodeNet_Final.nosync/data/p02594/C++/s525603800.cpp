//@source: 
//@create: 18:59:18 Sunday 02/08/2020
//@author: nghethuat102
#include <bits/stdc++.h>
using namespace std;

#define len(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define discrete(x) sort(all(x), x.erase(unique(all(x)), x.end())

void solve() {
    int n;
    cin >> n;
    if (n < 30) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    for (int it = 1; it <= t; ++it) {
        solve();
    }
    return 0;
}