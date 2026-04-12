#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位

int main(void){
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(ll i = 0; i < h; i++)
        cin >> s[i];
    vector<ll> c(h, 0);
    vector<ll> d(w, 0);
    for(ll i = 0; i < h; i++){
        bool check = true;
        for(ll j = 0; j < w; j++){
            if(s[i][j]=='#'){
                check = false;
                break;
            }
        }
        if(check==false) c[i] = 1;
    }
    for(ll i = 0; i < w; i++){
        bool check = true;
        for(ll j = 0; j < h; j++){
            if(s[j][i]=='#'){
                check = false;
                break;
            }
        }
        if(check==false) d[i] = 1;
    }
    for(ll i = 0; i < h; i++){
        if(c[i]==0) continue;
        for(ll j = 0; j < w; j++){
            if(d[j]==0) continue;
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}
