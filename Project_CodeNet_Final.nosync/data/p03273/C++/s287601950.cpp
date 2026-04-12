#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;

template<class T>bool chmax(T &a, const T &b) { if( a < b ) { a = b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if( b < a ) { a = b; return 1; } return 0;}

#ifdef LOCAL
    #define eprintf(...) printf(__VA_ARGS__)
#else
    #define eprintf(...) 1
#endif

#define ROUNDUP(a, b)         ( ((a) + ((b) - 1) ) / (b))
#define SET_ZERO(a)             ( memset((a), 0, sizeof(a)))
#define SET_NUM_ARRAY(a,b)    ( memset((a), b, sizeof(a)))
//#define int long long int //dont forget to change int to signed

int main() {
    int H, W;
    cin >> H >> W;
    char a[109][109];
    for (int i = 1; i <= H; i++) {
        char s[109];
        cin >> s;
        for (int j = 1; j <= W; j++) {
            a[i][j] = s[j-1];
        }
    }
    int r[109] = {}, c[109] = {};

    for (int i = 1; i <= H; i++) {
        char icolor = a[i][1];
        if (icolor == '#') continue;
        int flag = 1;
        for (int j = 2; j <= W; j++) {
            if (a[i][j] != icolor) {
                flag = -1;
                break;
            }
        }
        if (flag==1) r[i] = 1;
    }

    for (int i = 1; i <= W; i++) {
        char icolor = a[1][i];
        if (icolor == '#') continue;
        int flag = 1;
        for (int j = 2; j <= H; j++) {
            if (a[j][i] != icolor) {
                flag = -1;
                break;
            }
        }
        if (flag==1) c[i] = 1;
    }

    for (int i = 1; i <= H; i++) {
        if (r[i] == 0) {
            for (int j = 1; j <= W; j++) {
                if (c[j] == 0)cout << a[i][j];
            }
            cout << "\n";
        }
    }
    cout << endl;
}
