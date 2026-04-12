/*
 * Created by Dipta Das on 08-05-2019
 * Title: 
 * Problem Link: 
 * Editorial: 
 * Source Code: 
 * Comments: 
*/

#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)
#define whatis(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &i : ar) cin >> i;

    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        bool take = true;
        for (int j = 0; j <= i-1; ++j) {
            if (ar[i] < ar[j]) {
                take = false;
            }
        }
        if (take) ++cnt;
    }

    cout << cnt << endl;
    


    return 0;
}

