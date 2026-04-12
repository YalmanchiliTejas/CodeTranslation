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

int h, w; 
bool ok = false;
vector<string> grid;
void dfs(vector<vector<char>> pass, int y, int x){
    if(y==h-1 && x==w-1){
        pass[y][x] = '#';
        bool fg = true;
        rep(i, h){
            rep(j, w){
                if(pass[i][j] != grid[i][j])fg = false;
            }
        }
        if(fg)ok = true;
        return;
    }
    pass[y][x] = '#';
    if(y<h-1){
        dfs(pass, y+1, x);
    }
    if(x<w-1){
        dfs(pass, y, x+1);
    }
}

int main(){
    cin >> h >> w;
    vector<vector<char>> pass(h, vector<char>(w, '.'));
    grid.resize(h);
    rep(i, h){
        string s; cin >> s;
        grid[i] = s;
    }
    dfs(pass, 0, 0);
    if(ok) cout << "Possible" << ln;
    else cout << "Impossible" << ln;
}
