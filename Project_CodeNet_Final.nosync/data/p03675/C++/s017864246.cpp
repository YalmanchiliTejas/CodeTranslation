#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
const long long N = 2e5 + 5;
const long long mod = 1e9 + 7;
ll MODULAR_POWER(ll a , ll b , ll MOD) {
    if(b == 0) return 1LL;
    ll d = MODULAR_POWER(a , b / 2 , MOD);
    d *= d;
    d %= MOD;
    if(b % 2) d *= a;
    d %= MOD;
    return d;
}
ll MODULAR_INVERSE(ll a , ll MOD) {
    return MODULAR_POWER(a , MOD - 2 , MOD);
}
int a[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(8);
    cout << fixed;
    int n;
    cin >> n;
    rep(i , 1 , n) cin >> a[i];
    if(n % 2 == 0) {
        per(i , n , 2) {
            cout << a[i] << " ";
            i--;
        }
        rep(i , 1 , n) {
            cout << a[i] << " ";
            i++;
        }
    }
    else {
        per(i , n , 1) {
            cout << a[i] << " ";
            i--;
        }
        rep(i , 2 , n) {
            cout << a[i] << " ";
            i++;
        }
    }
    return 0;
}