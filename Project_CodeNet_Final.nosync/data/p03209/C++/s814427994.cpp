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
#include <stack>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define Yes(condition) if(condition){ cout << "Yes" << '\n'; }else{ cout << "No" << '\n'; }
#define YES(condition) if(condition){ cout << "YES" << '\n'; }else{ cout << "NO" << '\n'; }
#define yes(condition) if(condition){ cout << "yes" << '\n'; }else{ cout << "no" << '\n'; }




ll s[55], p[55];

ll dfs(ll n, ll x){
    if(n == 0){
        if(x <= 0) return 0;
        return 1;
    }
    if(x <= 1 + s[n - 1]) return dfs(n - 1,x - 1);
    return p[n - 1] + 1 + dfs(n - 1, x - 2 - s[n - 1]);
}

int main() {
    ll n, x;
    cin >> n >> x;
    s[0] = 1;
    p[0] = 1;
    REP(i, n){
        s[i + 1] = s[i] * 2 + 3;
        p[i + 1] = p[i] * 2 + 1;
    }
    cout << dfs(n, x) << endl;
}
