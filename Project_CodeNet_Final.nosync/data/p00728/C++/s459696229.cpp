#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n, n) {
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        cout << accumulate(begin(a) + 1, end(a) - 1, 0) / (n - 2) << endl;
    }
}

