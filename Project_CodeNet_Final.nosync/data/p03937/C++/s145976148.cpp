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
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    P cur = P(0, 0);
    s[0][0] = '.';
    while(true){
        if(cur == P(h-1, w-1)) break;
        int y = cur.first, x = cur.second;
        int ny = y+1, nx = x+1;
        if(ny < h && s[ny][x] == '#'){
            cur = P(ny, x);
            s[ny][x] = '.';
        }
        else if(nx < w && s[y][nx] == '#'){
            cur = P(y, nx);
            s[y][nx] = '.';
        }
        else break;
    }
    if(cur != P(h-1, w-1)){
        cout << "Impossible" << endl;
        return 0;
    }
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}
