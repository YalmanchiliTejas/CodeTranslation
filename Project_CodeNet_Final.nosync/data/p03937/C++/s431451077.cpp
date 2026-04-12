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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int h, w; cin >> h >> w;
    vector<vector<char>> pass(h+1, vector<char>(w+1, '.'));
    int cnt = 0;
    rep(i, h){
        string s; cin >> s;
        rep(j, w){
            pass[i][j] = s[j];
            if(s[j] == '#')cnt++;
        }
    }
    
    int y = 0, x = 0; //現在地
    while(true){
        cnt--;
        if(pass[y+1][x] == '.' && pass[y][x+1] == '.') break;
        if(pass[y+1][x] == '#') y++;
        else x++;
    }

    if(cnt == 0) cout << "Possible" << ln;
    else cout << "Impossible" << ln;
}
