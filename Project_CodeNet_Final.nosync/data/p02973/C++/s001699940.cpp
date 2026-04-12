#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using Graph = std::vector<std::vector<int>>;
using WGraph = std::vector<std::vector<std::pair<int, long long>>>;
using ll = long long;
using namespace std;

int main() {
    int n = 0; cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }

    vector<ll> dec(n, -1);
    for (int i=0; i<n; i++) {
        *(lower_bound(dec.rbegin(), dec.rend(), a.at(i)) - 1) = a.at(i);
    }

    for (int i=0; i<n; i++) {
        if (dec.at(i) == -1) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
 