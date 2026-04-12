#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    rep(i, H){
        string s; cin >> s;
        rep(j, W){
            grid[i][j] = s[j];
        }
    }

    rep(i, H){
        bool fg = true;
        rep(j, W){
            if(grid[i][j] == '#') fg = false;
        }
        if(fg){
            rep(j, W) grid[i][j] = 'x';
        }
    }

    rep(j, W){
        bool fg = true;
        rep(i, H){
            if(grid[i][j] == '#') fg = false;
        }
        if(fg){
            rep(i, H) grid[i][j] = 'x';
        }
    }
    rep(i, H){
        bool fg = false;
        rep(j, W){
            char c = grid[i][j];
            if(c != 'x') fg = true, cout << c;
        }
        if(fg)cout << ln;
    }
    
}