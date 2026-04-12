#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    int max = h[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i){
        if (max <= h[i]) {
            ++cnt;
            max = h[i];
        }
    }

    cout << cnt << endl;
}
