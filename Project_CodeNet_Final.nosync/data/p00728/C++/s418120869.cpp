#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;

int main() {
    while (1) {
        int n;
        cin >> n;
        if (!n) return 0;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int sum = 0;
        for (int i = 1; i < n - 1; ++i) {
            sum += a[i];
        }
        cout << sum / (n - 2) << "\n";
    }
}

