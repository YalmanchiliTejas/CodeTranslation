#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
    int h, w;
    cin >> h >> w;
    char a[h][w];
    rep(i, h) {
        rep(j, w) cin >> a[i][j];
    }

    int t[h] = {};
    int y[w] = {};

    rep(i, h) {
        rep(j, w) {
            if(a[i][j] == '#') break;
            if(j == w-1) t[i]++;
        }
    }

    rep(j, w) {
        rep(i, h) {
            if(a[i][j] == '#') break;
            if(i == h-1) y[j]++;
        }
    }

    int cntt = 0;
    int cnty = 0;
    rep(i, h) {
        if(t[i]>0) cntt++;
    }
    rep(i, w) {
        if(y[i]>0) cnty++;
    }

    char ans[h-cntt][w-cnty];
    int cntx = 0;
    rep(i, h) {
        int cntyy = 0;
        rep(j, w) {
            if(t[i]==0 && y[j]==0) {
                char tmp = a[i][j];
              	cout << tmp;
            }
            if(j==w-1 && t[i] == 0) cout << endl;
        }
        cntx++;
    }

    return 0;
}