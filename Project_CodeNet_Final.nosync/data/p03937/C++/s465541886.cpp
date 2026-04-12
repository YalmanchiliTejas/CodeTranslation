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
    int counter = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(a[i][j] == '#') {
                counter++;
            }
        }
    }
    if(counter == h + w - 1) {
        puts("Possible");
    } else {
        puts("Impossible");
    }
    return 0;
}