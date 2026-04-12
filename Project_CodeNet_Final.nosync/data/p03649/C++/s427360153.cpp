#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    ll ret = 0;
    bool found = true;
    while (found) {
        found = false;
        for (int i = 0; i < n; i++) {
            if (v[i] >= n) {
                found = true;
                ll x = v[i] / n;
                v[i] %= n;
                ret += x;
                for (int j = 0; j < n; j++) {
                    if (i == j)continue;
                    v[j] += x;
                }
            }
        }
    }

    cout << ret << endl;
    return 0;
}