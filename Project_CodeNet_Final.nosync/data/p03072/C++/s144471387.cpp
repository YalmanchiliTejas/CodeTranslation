// https://atcoder.jp/contests/abc124/tasks/abc124_a

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0, high = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (auto x : v) {
        if (x >= high) {
            ans++;
            high = x;
        }
    }

    cout << ans << '\n';

    return 0;
}