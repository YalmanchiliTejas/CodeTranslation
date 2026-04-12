#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <climits>
#include <unordered_map>
#include <queue>


#define rep(i, n) for(int i = 0, end = (int)(n); i < end; i++)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

inline int ctoi(char c) {
    return (int)(c -'0');
}

// ----------------------------------------------------------
char field[111][111];

int main() {
    rep(i, 111) rep(j, 111){
        field[i][j] = 'x';
    }
    ll h, w;
    cin >> h >> w;
    rep(i, h) rep(j, w) {
        cin >> field[i][j];
    }
    rep (i, h) {
        bool flag = true;
        rep(j, w) {
            if (field[i][j] == '#') {
                flag = false;
                break;
            }
        }
        if (flag) {
            rep(j, w) {
                field[i][j] = 'x';
            }
        }
    }
    rep (j, w) {
        bool flag = true;
        rep(i, h) {
            if (field[i][j] == '#') {
                flag = false;
                break;
            }
        }
        if (flag) {
            rep(i, h) {
                field[i][j] = 'x';
            }
        }
    }
/*
    rep(i, h) {
        rep(j, w) {
            cout << field[i][j];
        }
        cout << endl;
    }
*/
    rep(i, h) {
        bool temp = false;
        rep(j, w) {
            if (field[i][j] != 'x') {
                cout << field[i][j];
                temp = true;
            }
        }
        if (temp) {
            cout << endl;
        }
    }
    return 0;
}