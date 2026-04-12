#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int h, w; cin >> h >> w;
    vector<string> grid(h); rep(i, h) cin >> grid[i];
    rep(i, h){
        bool all_w = true;
        rep(j, w)if(grid[i][j]!='.')all_w = false;
        if(all_w){
            rep(j, w)grid[i][j] = 'x';
        }
    }
    rep(j, w){
        bool all_w = true;
        rep(i, h)if(grid[i][j]=='#')all_w = false;
        if(all_w){
            rep(i, h)grid[i][j] = 'x';
        }
    }
    rep(i, h){
        bool fg = false;
        rep(j, w){
            if(grid[i][j] != 'x'){cout << grid[i][j]; fg = true;}
        }if(fg)cout << ln;
    }
}
