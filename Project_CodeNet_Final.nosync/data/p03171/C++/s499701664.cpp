/**
 *    author:  FromDihPout
 *    created: 2020-07-27
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    bool maximize = n & 1;
    vector<long long> prev(n);
    for (int i = 0; i < n; i++) {
        if (maximize)
            prev[i] = a[i];
        else
            prev[i] = -a[i];
    }
    for (int size = 1; size < n; size++) {
        maximize = !maximize;
        vector<long long> curr(n - size);
        for (int i = 0; i < n - size; i++) {
            if (maximize) {
                curr[i] = max(prev[i + 1] + a[i], prev[i] + a[i + size]);
            }
            else {
                curr[i] = min(prev[i + 1] - a[i], prev[i] - a[i + size]);
            }
        }
        prev = curr;
    }
    cout << prev[0] << endl;
    return 0;
}