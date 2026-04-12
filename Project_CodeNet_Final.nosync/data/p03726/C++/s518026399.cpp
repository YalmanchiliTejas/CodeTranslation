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
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>



using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)

















vector<vector<ll>> g;

bool dfs(ll now, ll par){
    bool f = true;
    for(auto &child : g[now]){
        if(child == par) continue;
        bool b = dfs(child, now);
        if(b){
            if(f) f = false;
            else {
                cout << "First" << endl;
                exit(0);
            }
        }
    }
    return f;
}


int main(){
    ll n;
    cin >> n;
    g.resize(n);
    REP(i, n - 1){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool b = dfs(0, -1);
    cout << (b? "First" : "Second") << endl;
}