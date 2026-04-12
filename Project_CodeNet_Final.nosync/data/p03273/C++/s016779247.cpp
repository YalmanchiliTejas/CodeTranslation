#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    int h,w;
    cin >> h >> w;
    ve<string> fi(h);
    rep(i,h) cin >> fi[i];
    ve<ve<bool>> ng(h,ve<bool>(w,false));
    rep(i,h){
        bool fl = true;
        rep(j,w){
            if(fi[i][j] == '#'){
                fl = false;
                break;
            }
        }
        if(fl){
            rep(j,w) ng[i][j] = true;
        }
    }
    rep(j,w){
        bool fl = true;
        rep(i,h){
            if(fi[i][j] == '#'){
                fl = false;
                break;
            }
        }
        if(fl){
            rep(i,h) ng[i][j] = true;
        }
    }
    rep(i,h){
        bool fl = false;
        rep(j,w){
            if(!ng[i][j]){
                cout << fi[i][j];
                fl = true;
            }
        }
        if(fl) cout << endl;
    }
    return 0;
}
