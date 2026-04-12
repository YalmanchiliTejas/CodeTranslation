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

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(int i = 0; i < n; i++)
#define RREP(i, n) for(int i = n - 1; i >= 0; i--)
#define REP2(i, n, k) for(int i = 0; i < n; i += k)



int main() {
    ll n, k;
    
    cin >> n >> k;
    
    if(k == 0){
        cout << n * n << endl;
        return 0;
    }
    
    ll ans = 0;
    for(ll i = k + 1; i <= n; i++){
        /*
        for(ll j = k; j < i; j++){
            ans += (n - j) / i + 1;
        }
        */
        
        ll t = i - k;
        ans += t * ((n - k) / i + 1);
        /*
        ll j;
        for(j = k; j < i; j++){
            if(j + (i * ((n - k) / i)) > n){
                break;
            }
        }
        if(j != k - 1){
            ans -= (i - j);
        }
        */
        ll le = k, ri = i - 1, ce = (le + ri) / 2;
        while(ri - le > 1){
            if(ce + (i * ((n - k) / i)) > n){
                ri = ce;
            }
            else{
                le = ce;
            }
            ce = (le + ri) / 2;
        }

        if(!((ri + (i * ((n - k) / i)) <= n))){
            ans -= (i - ce - 1);
        }
        // cout << ans << endl;
    }
    
    cout << ans << endl;
}
