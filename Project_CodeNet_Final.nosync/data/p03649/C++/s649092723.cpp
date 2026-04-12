#include "bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i ++) 

int main() {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i ++) {
                cin >> a[i];
        }
        long long ans = 0;
        while (true) {
                bool end = true;
                for (int i = 0; i < n; i ++) {
                        if (a[i] < n) continue;
                        end = false;
                        long long div = a[i] / n;
                        long long mod = a[i] % n;
                        a[i] = mod;
                        for (int j = 0; j < n; j ++) if (i != j) {
                                a[j] += div;
                        }
                        ans += div;
                }
                if (end) break;
        }
        cout << ans << endl;
        return 0;
}

