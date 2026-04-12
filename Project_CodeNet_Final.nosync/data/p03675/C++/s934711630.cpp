#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (i & 1) {
            v2.push_back(c);
        } else v1.push_back(c);
    }

    if (n & 1) {
        reverse(v1.begin(), v1.end());
        for(auto c: v1) cout << c << ' ';
        for(auto c: v2) cout << c << ' ';
        
    } else {
        reverse(v2.begin(), v2.end());
        for(auto c: v2) cout << c << ' ';
        for(auto c: v1) cout << c << ' ';
    }
    cout << endl;
}