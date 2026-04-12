#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {

    int h,w; cin >> h >> w;
    char g[101][101];
    bool f = true;


    rep(i,h){
        rep(j,w){
            cin >> g[i][j];
        }
    }

    rep(i,h){
        f = true;
        rep(j,w){
            if(g[i][j] != '.'){
                f = false;
            }
        }
        if(f){
            rep(j,w){
                g[i][j] = 'b';
            }
        }
    }
    rep(i,w){
        f = true;
        rep(j,h){

            if(g[j][i] == '#'){
                f = false;
            }
        }
        if(f){
            rep(j,h){
                g[j][i] = 'b';
            }
        }
    }

    rep(i,h){
        f = true;
        rep(j,w){
            if(g[i][j] != 'b') {
                cout << g[i][j];
                f = false;
            }
        }
        if(!f) cout << endl;
    }

    return 0;
}









