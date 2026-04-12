#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> hw(h, vector<char>(w));
    rep(i, h) rep(j, w) cin >> hw[i][j];
    vector<int> h_idx;
    vector<int> w_idx;
    rep(i, h) {
        bool flg = true;
        rep(j, w) if ( hw[i][j] == '#' ) flg = false;
        if ( flg ) {
            h_idx.push_back(i);
        }
    }
    rep(j, w) {
        bool flg = true;
        rep(i, h) if ( hw[i][j] == '#' ) flg = false;
        if ( flg ) {
            w_idx.push_back(j);
        }
    }
    rep(i, h) {
        bool h_flg = false;
        for ( auto idx : h_idx ) {
            if ( idx == i ) h_flg = true;
        }
        if ( h_flg ) continue;
        rep(j, w) {
            bool w_flg = false;
            for ( auto idx : w_idx ) {
                if ( idx == j ) w_flg = true;
            }
            if ( h_flg || w_flg ) continue;
            cout << hw[i][j];
        }
        if ( !h_flg ) cout << endl;
    }
    return 0;
}
