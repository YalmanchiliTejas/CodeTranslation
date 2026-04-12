#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    reverse(a.begin(), a.end());
    vector<int> lis{a[0]};
    for (int i = 1; i < n; i++) {
        auto itr = upper_bound(lis.begin(), lis.end(), a[i]);
        if (itr == lis.end())
            lis.push_back(a[i]);
        else
            *itr = a[i];
    }
    cout << lis.size() << endl;
}