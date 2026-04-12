#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

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

    ll n = 0;
    for (ll i = 0; i < h; i++){
        for (ll j = 0; j < w; j++){
            if (a[i][j] == '#'){
                n++;
            }
        }
    }

    if (n == h+w-1){
        cout << "Possible" << endl;
    }
    else{
        cout << "Impossible" << endl;
    }
}