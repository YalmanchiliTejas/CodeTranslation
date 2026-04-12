#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

vector<vector<char>> grid;
vector<vector<bool>> seen;
bool ok = false;
int tx[2] = {0, 1};
int ty[2] = {1, 0};
int h, w;

void dfs(int i, int j) {
    seen[i][j] = true;
    if(i == h-1 && j == w-1) {
        for(int ii = 0; ii < h; ii++) for(int jj = 0; jj < w; jj++) {
            if(grid[ii][jj] == '#' && !seen[ii][jj]) return;
        }
        ok = true;
    }
    for(int k = 0; k < 2; k++) {
        int ni = i + tx[k];
        int nj = j + ty[k];
        if(ni >= 0 && ni < h && nj >= 0 && nj < w && !seen[ni][nj] && grid[ni][nj] == '#') {
            dfs(ni, nj);
        }
    }
    seen[i][j] = false;
}

int main(){
    cin >> h >> w;
    grid.assign(h, vector<char>(w));
    seen.assign(h, vector<bool>(w, false));
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> grid[i][j];
    dfs(0, 0);
    printf("%s\n", ok?"Possible":"Impossible");
}