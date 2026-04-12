#include <bits/stdc++.h>
using namespace std;

int solve(int n, int l, int r) {
    vector<int> A(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int year = l; year <= r; year++) {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (year % A[i] == 0) {
                if (i % 2 == 0) ans++;
                flag = true;
                break;
            }
        }
        if (!flag && n % 2 == 0) ans++;
    }
    return ans;
}

int main(void) {
    int n, l, r;
    vector<int> ans;
    while (1) {
        cin >> n >> l >> r;
        if (!n && !l && !r) break;
        ans.push_back(solve(n, l, r));
    }
    for (int i : ans) cout << i << endl;
}

