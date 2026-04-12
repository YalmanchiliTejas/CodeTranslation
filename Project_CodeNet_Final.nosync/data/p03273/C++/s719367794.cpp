#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int H, W;
    cin >> H >> W;
    char a[H][W];
    rep(i, H){
        rep(j, W) cin >> a[i][j];
    }
    set<int> iw;
    set<int> jw;
    rep(i, H){
        bool is_w = true;
        rep(j, W) if(a[i][j] == '#') is_w = false;
        if(is_w) iw.insert(i);
    }
    rep(j, W){
        bool is_w = true;
        rep(i, H) if(a[i][j] == '#') is_w = false;
        if(is_w) jw.insert(j);
    }
    rep(i, H){
        if(iw.count(i) == 0){
            rep(j, W){
                if(jw.count(j) == 0) cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}