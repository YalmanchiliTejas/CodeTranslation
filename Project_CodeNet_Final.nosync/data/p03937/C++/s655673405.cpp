#include <bits/stdc++.h>

using namespace std;


int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> P;
    int cur = 0;
    for(int i = 0; i < h; i++) {
        int x;
        for(int j = 0; j < w; j++) {
            if(a[i][j] == '#') {
                x = j;
            }
        }
        P.push_back(make_pair(cur, x));
        cur = x;
    }
    vector<vector<char>> v(h, vector<char>(w, '.'));
    for(int i = 0; i < h; i++) {
        int fst = P[i].first;
        int snd = P[i].second;
        for(int j = fst; j <= snd; j++) {
            v[i][j] = '#';
        }
    }
    if(v == a) {
        puts("Possible");
    } else {
        puts("Impossible");
    }
    return 0;
}