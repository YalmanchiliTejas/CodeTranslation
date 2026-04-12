#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)





int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    REP(i, h){
        cin >> a[i];
    }
    bool deleted[105][105] = {};
    REP(i, h){
        ll j;
        for(j = 0; j < w; j++){
            if(a[i][j] == '#') break;
        }
        if(j == w){
            REP(k, w){
                deleted[i][k] = true;
            }
        }
    }
    REP(i, w){
        ll j;
        for(j = 0; j < h; j++){
            if(a[j][i] == '#') break;
        }
        if(j == h){
            REP(k, h){
                deleted[k][i] = true;
            }
        }
    }
    
    REP(i, h){
        bool e = false;
        REP(j, w){
            if(!deleted[i][j]){
                cout << a[i][j];
                e = true;
            }
        }
        if(e) cout << endl;
    }
}
