#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll h,w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for (ll i = 0;i < h;i++){
        for (ll j = 0;j < w;j++){
            cin >> a[i][j];
        }
    }
    vector<bool> wh(h);
    for (ll i = 0; i < h; i++){
        bool b = true;
        for (ll j = 0; j < w; j++){
            if (a[i][j] == '#'){
                b = false;
            }
        }
        wh[i] = b;
    }
    vector<ll> ww(w);
    for (ll j = 0; j < w; j++){
        bool b = true;
        for (ll i = 0; i < h; i++){
            if (a[i][j] == '#'){
                b = false;
            }
        }
        ww[j] = b;
    }

    for (ll i = 0;i < h;i++){
        if (wh[i]){
            continue;
        }
        for (ll j = 0;j < w;j++){
            if (ww[j]){
                continue;
            }
            cout << a[i][j];
        }
        cout << endl;
    }
    
}