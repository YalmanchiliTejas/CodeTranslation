#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T, class U> inline bool chmax(T& a,U b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> inline bool chmin(T& a,U b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> c(n, 0);
    for (auto& e : a) cin >> e;
    
    long long ans = 0;
    while (true) {
        fill(c.begin(), c.end(), 0);
        for (int i = 0; i < n; i++) {
            if (a[i] < n) continue;
            long long p = a[i] / n;
            a[i] %= n;
            ans += p;
            for (int j = 0; j < n; j++) {
                if (i != j) c[j] += p;
            }
        }
        
        bool ok = true;
        for (int i = 0; i < n; i++) {
            a[i] += c[i];
            if (a[i] >= n) ok = false;
        }
        
        if (ok) break;
    }
    
    cout << ans << endl;
    return 0;
}