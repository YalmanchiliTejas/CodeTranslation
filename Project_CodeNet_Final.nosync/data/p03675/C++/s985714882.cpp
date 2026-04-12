#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans;
    for (int i = n-1; i >= 0; i-=2) {
        ans.push_back(a[i]);
    }
    for (int i = (n % 2); i < n; i+=2) {
        ans.push_back(a[i]);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i == ans.size()-1) {
            cout << endl;
        }
        else {
            cout << " ";
        }
    }
}