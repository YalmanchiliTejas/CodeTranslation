#include<bits/stdc++.h>

using namespace std;

string s[8];

int main() {
    int h, w; scanf("%d %d", &h, &w);
    for(int i = 0; i<h; ++i) cin >> s[i];
    if( s[0][0] != '#' || s[h-1][w-1] != '#' ) {
        puts("Impossible");
        return 0;
    }
    vector<int> prv;
    for(int i = 0; i<h; ++i) if( s[i][0] == '#' ) prv.push_back(i);
    for(int j = 1; j<w; ++j) {
        vector<int> now;
        for(int i = 0; i<h; ++i) if( s[i][j] == '#' ) now.push_back(i);
        if( prv.back() != now.front() ) {
            puts("Impossible");
            return 0;
        }
        prv = now;
    }
    puts("Possible");
}
