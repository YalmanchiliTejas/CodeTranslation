#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    vector<bool> ver(w, false), hor(h, false);
    rep(i,h){
        bool compress = true;
        rep(j,w){
            if(a[i][j] == '#') compress = false;
        }
        if(compress) hor[i] = true;
    }
    rep(j,w){
        bool compress = true;
        rep(i,h){
            if(a[i][j] == '#') compress = false;
        }
        if(compress) ver[j] = true;
    }
    rep(i,h){
        if(hor[i]) continue;
        rep(j,w){
            if(ver[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}