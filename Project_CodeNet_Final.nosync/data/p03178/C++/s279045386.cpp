#include <bits/stdc++.h>

using namespace std;

const int kMod = 1e9 + 7;

void upd(int& x, int y) {
    x += y;
    if (x >= kMod) 
        x -= kMod;
    if (x < 0)
        x += kMod;
}

int main() {
    string k; cin >> k;
    int n = k.size();

    int d; cin >> d;
    
    
    vector<vector<int>> right(n + 1, vector<int>(d, 0));
    right[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int x = 0; x < 10; ++x) {
            for (int j = 0; j < d; ++j) {
                upd(right[i][(j + x) % d], right[i + 1][j]);
            }
        }    
    }

    int total = 0; upd(total, -1);
   
    vector<int> pw(n + 1, 1);
    for (int i = 0; i < n; ++i)
        pw[i + 1] = pw[i] * 10 % d;

    int have = 0; 
    for (int i = 0; i < n; ++i) {
        for (int d1 = 0; d1 < (k[i] - '0'); ++d1) {
            int r1 = (have + d1) % d;
            int r2 = (d - r1) % d;
            upd(total, right[i + 1][r2]);
        }
        have = (have + k[i] - '0') % d;
    }
    if (have == 0) upd(total, 1);

    cout << total << endl;

    return 0;
}
