#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
map<ll, ll> mp;
int main(void){
    // Your code here!
    ll h, w;
    string st[100];
    cin >> h >> w;
    for (ll i = 0; i < h; i++) cin >> st[i];
    for (ll i = 0; i < w; i++){
        bool jud = true;
        for (ll j = 0; j < h; j++){
            if (st[j][i] == '#') jud = false;
        }
        if (jud) mp[i]++;
    }
    for (ll i = 0; i < h; i++){
        bool jud = true;
        for (ll j = 0; j < st[i].length(); j++){
            if (st[i][j] == '#') jud = false;
        }
        if (!jud){
            for (ll j = 0; j < w; j++){
                if (mp[j] == 0) cout << st[i][j];
            }
            cout << endl;
        }
    }
}
