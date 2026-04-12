#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
    int h, w;
    cin >> h >> w;
    char maze[110][110];
    rep(i, h) rep(j, w) cin >> maze[i][j];

    vector<bool> skiprow(110, true), skipline(110, true);
    
    rep(i, h) {
        rep(j, w) {
            //bool skip = true;
            if (maze[i][j] =='#') {
                skiprow[i] = false;
                break;
            }
        }
    }
    rep(j, w) {
        rep(i,h)  {
            if (maze[i][j] == '#') {
                skipline[j] = false;
                break;
            }
        }
    }
    rep (i, h) {
        rep(j, w) {
            /*if (skiprow[i] || skipline[j]) {
                if (j == w-1) cout << endl;
                continue;
            } 
            cout << maze[i][j];
            if (j == w-1) cout << endl;*/
            if (!skiprow[i] && !skipline[j]) {
                cout << maze[i][j];
            }
            if (j == w-1 && !skiprow[i]) cout << endl;
        }
    }
    
    //cout << endl;
    return 0;
}