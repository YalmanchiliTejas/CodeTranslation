#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h,(vector<char>(w)));
    rep(i,h){
        rep(j,w) cin >> a[i][j];
    }
    vector<bool> flag_h(h);
    vector<bool> flag_w(w);
    rep(i,h){
        rep(j,w){
            if(a[i][j] == '#') flag_h[i] = true;
        }
    }
    rep(j,w){
        rep(i,h){
            if(a[i][j] == '#') flag_w[j] = true;
        }
    }
    rep(i,h){
        rep(j,w){
            if(flag_h[i] && flag_w[j]) cout << a[i][j];
        }
        if(flag_h[i]) cout << endl;
    }
    return 0;
}