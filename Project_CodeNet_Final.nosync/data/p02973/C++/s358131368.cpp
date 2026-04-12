#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    multiset<int> s;
    for (int i = n - 1; i >= 0; i--) {
        auto itr = s.upper_bound(a[i]);
        if (itr == s.end()) {
            s.insert(a[i]);
        } else {
            s.erase(itr);
            s.insert(a[i]);
        }
    }
    cout << s.size() << "\n";
    return 0;
}