#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll inf = INT64_MAX / 4;

int p[200000], n, k;

ll comb(ll n, ll k) {
    if (k == 0) return 1;
    return (comb(n - 1, k - 1) * n) / k;
}

int main() {
    string n;
    ll k, r = 0;
    cin >> n >> k;
    r += comb(n.size() - 1, k) * pow(9, k);
    string t;
    for (int i = 0; i < n.size(); i++)t.push_back('0');
    if (k == 1) {
        for (t[0] = '1'; t[0] <= '9'; t[0]++) {
            if (t <= n) r++;
        }
    }
    if (k == 2) {
        for (t[0] = '1'; t[0] <= '9'; t[0]++) {
            for (int i = 1; i < t.size(); i++) {
                for (t[i] = '1'; t[i] <= '9'; t[i]++) {
                    if (t <= n) r++;
                }
                t[i] = '0';
            }
        }
    }
    if (k == 3) {
        for (t[0] = '1'; t[0] <= '9'; t[0]++) {
            for (int i = 1; i + 1 < t.size(); i++) {
                for (t[i] = '1'; t[i] <= '9'; t[i]++) {
                    for (int j = i + 1; j < t.size(); j++) {
                        for (t[j] = '1'; t[j] <= '9'; t[j]++) {
                            if (t <= n) r++;
                        }
                        t[j] = '0';
                    }
                }
                t[i] = '0';
            }
        }
    }
    cout << r << endl;
}
