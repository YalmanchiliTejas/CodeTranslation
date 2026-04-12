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




int main() {
    ll n;
    cin >> n;
    priority_queue<ll> que;
    REP(i, n){
        ll a;
        cin >> a;
        que.push(a);
    }
    
    ll ans = 0;
    for(;;){
        ll t1 = que.top(), t2 = t1 + ans; que.pop();
        if(n > t2) break;
        
        ans += t2 / n;
        t1 -= n * (t2 / n) + t2 / n;
        
        que.push(t1);
    }
    cout << ans << '\n';
}
