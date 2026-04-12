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
    vector<int> iw;
    vector<int> jw;
    rep(i, H){
        bool is_w = true;
        rep(j, W) if(a[i][j] == '#') is_w = false;
        if(is_w) iw.push_back(i);
    }
    rep(j, W){
        bool is_w = true;
        rep(i, H) if(a[i][j] == '#') is_w = false;
        if(is_w) jw.push_back(j);
    }
    rep(i, H){
        if(count(iw.begin(), iw.end(), i) == 0){
            rep(j, W){
                if(count(jw.begin(), jw.end(), j) == 0) cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}