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
    ll n;
    cin >> n;
    vector<ll> s(n);
    REP(i, n){
        cin >> s[i];
    }
    
    ll ans = 0;
    for(ll i = 1; i < n; i++){
        ll sum = 0;
        vector<bool> used(n);
        for(ll j = 0; j < n - i; j += i){
            ll k = n - 1 - j;
            
            if(used[j]) break;
            used[j] = true;
            sum += s[j];
            
            if(used[k]) break;
            used[k] = true;
            sum += s[k];
            
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}