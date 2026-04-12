#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

bool isPalindrome(string s) {
    string t(s.rbegin(), s.rend());
    return s == t;
}

int main(void) {
    ll H, W;
    cin >> H >> W;
    vector<string> map(H);
    vector<bool> rows(H, false);
    vector<bool> cols(W, false);
    for(ll h = 0;h < H;h++) {
        cin >> map[h];
        for(ll w = 0;w < W;w++) {
            if(map[h][w] == '#') {
                rows[h] = true;
                cols[w] = true;
            }
        }
    }
    for(ll h = 0;h < H;h++) {
        if(rows[h]) {
            for(ll w = 0;w < W;w++) {
                if(cols[w]) cout << map[h][w];
            }
            cout << endl;
        }
    }
    return 0;
}
