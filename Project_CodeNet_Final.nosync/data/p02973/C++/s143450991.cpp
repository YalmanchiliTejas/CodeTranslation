#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a[100005] = {};
    vector<int> b = {0};
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] >= b.back()) b.push_back(a[i]);
        else *upper_bound(b.begin(), b.end(), a[i]) = a[i];
    }
    cout << (int)b.size() - 1;
}
