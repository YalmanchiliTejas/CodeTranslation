#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll dis(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    ll h, w;
    cin >> h >> w;

    vector<string> a(h);
    set<ll> ban_h;
    set<ll> ban_w;

    rep(i, h){
        cin >> a[i];
    }

    rep(i, h){
        bool flg = true;
        rep(j, w){
            if (a[i][j] == '#'){
                flg = false;
            }
        }
        if (flg){
            ban_h.insert(i);
        }
    }

    rep(i, w){
        bool flg = true;
        rep(j, h){
            if (a[j][i] == '#'){
                flg = false;
            }
        }
        if (flg){
            ban_w.insert(i);
        }
    }


    rep(i, h){
        bool flg = false;
        rep(j, w){
            if (ban_h.find(i) != ban_h.end() || ban_w.find(j) != ban_w.end()){
                continue;
            }else{
                cout << a[i][j];
                flg = true;
            }
        }
        if (flg){
            cout << endl;
        }
    }

    return 0;
}
