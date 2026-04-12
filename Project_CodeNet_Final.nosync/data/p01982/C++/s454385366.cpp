#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using ll = long long;
int main() {
    ll n, l, r;
    while(cin >> n >> l >> r, n) {
        vector<ll> A(n);
        for(auto &x:A) cin >> x;
        auto uruu = [&]() {
            ll ctr = 0;
            for(int i = l; i <= r; i++) {
                int j = 0;
                while(j < n && i % A[j] != 0) j++;
                ctr += (j % 2 == 0);
            }
            return ctr;
        };
        cout << uruu() << endl;
    }
}
