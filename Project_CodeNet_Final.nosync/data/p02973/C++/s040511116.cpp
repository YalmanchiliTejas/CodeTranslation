#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

typedef long long ll;
const int MAXN = 100010;

int n;
ll A[MAXN];

void solve() {
    vector<ll> IS = {-A[0]};
    for (int i=1;i<n;i++) {
        auto pos = upper_bound(IS.begin(), IS.end(), -A[i]);
        if (pos == IS.end()) {
            IS.push_back(-A[i]);
        } else {
            *pos = -A[i];
        }
    }
    cout << IS.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> A[i];
    }
    solve();
}
