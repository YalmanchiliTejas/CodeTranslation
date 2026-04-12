#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll h, w;
    cin >> h >> w;
    char grid[h][w];
    for (ll i = 0; i < h;i++){
        for (ll j = 0; j < w;j++){
            cin >> grid[i][j];
        }
    }
    bool flagh[h];
    for (ll i = 0; i < h; i++) flagh[i] = false;
    bool flagw[w];
    for (ll i = 0; i < w; i++) flagw[i] = false;
    for (ll i = 0; i < h;i++){
        for (ll j = 0; j < w;j++){
            if (grid[i][j] == '#'){
                flagh[i] = true;
                flagw[j] = true;
            }
        }
    }
    for (ll i = 0; i < h;i++){
        if(flagh[i]){for (ll j = 0; j < w;j++){
            if (flagw[j]) cout << grid[i][j];
        }
        cout << endl;}
    }
}