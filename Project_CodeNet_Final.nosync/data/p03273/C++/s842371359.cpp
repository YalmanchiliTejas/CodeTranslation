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
    vector<bool> H(h, false), W(w, false);
    vector<vector<char>> grid(h, vector<char>(w));
    rep(i,h)rep(j,w) cin >> grid[i][j];
    rep(i,h){
        bool del = true;
        rep(j,w) if(grid[i][j] == '#') del = false;
        if(del) H[i] = true;
    }
    rep(j,w){
        bool del = true;
        rep(i,h) if(grid[i][j] == '#') del = false;
        if(del) W[j] = true;
    }
    rep(i,h){
        rep(j,w){
            if(!H[i] && !W[j]) cout << grid[i][j];
        }
        if(!H[i]) cout << endl;
    }
    return 0;
}