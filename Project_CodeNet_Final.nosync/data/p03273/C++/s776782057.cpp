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
    string *map;
    bool *ignoredH, *ignoredW;
    cin >> H >> W;
    map = new string[H];
    ignoredW = new bool[W];
    ignoredH = new bool[H];
    for(ll h = 0;h < H;h++) {
        bool flag = true;
        cin >> map[h];
        for(ll w = 0;w < W;w++) {
            if(map[h][w] != '.') flag = false;
        }
        if(flag) ignoredH[h] = true;
    }
    for(ll w = 0;w < W;w++) {
        bool flag = true;
        for(ll h = 0;h < H;h++) {
            if(map[h][w] != '.') flag = false;
        }
        if(flag) ignoredW[w] = true;
    }
    for(ll h = 0;h < H;h++) {
        if(!ignoredH[h]) {
            for(ll w = 0;w < W;w++) {
                if(!ignoredW[w]) cout << map[h][w];
            }
            cout << endl;
        }
    }
    return 0;
}
