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
#include <random>



using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)












int main(){
    ll n, l, r;
    while(cin >> n >> l >> r, n || l || r){
        vector<ll> a(n);
        REP(i, n){
            cin >> a[i];
        }
        ll ans = 0;
        for(ll x = l; x <= r; x++){
            REP(i, n){
                if(x % a[i] == 0){
                    if(i % 2 == 0){
                        ans++;
                    }
                    break;
                }
                if(i == n - 1 && n % 2 == 0){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
