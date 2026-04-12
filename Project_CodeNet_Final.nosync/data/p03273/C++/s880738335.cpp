#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll H,W;
    cin >> H >> W;
    char a[H][W];
    ll h[H];
    rep(i,H) h[i] = 0;
    ll w[W];
    rep(i,W) w[i] = 0;
    rep(i,H){
        rep(j,W){
            cin >> a[i][j];
            if(a[i][j]=='.'){
                h[i]++;
                w[j]++;
            }
        }
    }
    rep(i,H){
        if(h[i]<W){
            rep(j,W){
                if(w[j]<H) cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
