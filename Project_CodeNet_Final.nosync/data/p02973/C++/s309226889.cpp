#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
constexpr long INF = 1L << 62;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long n, k; cin >> n;
    vector<long> a(n); for(int i = 0; i < n; ++i) cin >> a[i], a[i] *= -1;

    vector<long> ans(n * 2, INF);

    for(int i = 0; i < n; ++i) 
        *lower_bound(ans.begin(), ans.end(), a[i] + 1) = a[i];

    cout << lower_bound(ans.begin(), ans.end(), INF) - ans.begin() << endl;
    return 0;
}