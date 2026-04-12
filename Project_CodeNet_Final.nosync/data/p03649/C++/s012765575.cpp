#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    long long cnt = 0;
    while (true) {
        long long s = 0;
        for (int i = 0; i < n; i++) {
            s += a.at(i) / n;
        }
        cnt += s;
        
        bool ok = true;
        for (int i = 0; i < n; i++) {
            a.at(i) = a.at(i) - a.at(i) / n * n + s - a.at(i) / n;
            if (a.at(i) >= n) ok = false;
        }
        if (ok) break;
    }
    cout << cnt << endl;
}