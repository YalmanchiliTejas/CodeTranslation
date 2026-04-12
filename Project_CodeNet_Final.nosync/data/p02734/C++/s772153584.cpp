#include <cstring>
#include <cassert>
#include <utility>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <tuple>
#include <climits>
#include <limits>
#include <deque>
#include <list>
#include <array>
#include <stack>
#include <queue>
#include <random>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
 
#define init ios::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
#define setpr(x) cout << setprecision((x))
#define PI atan(1)*4
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define in insert
#define er erase
#define mk(a , b) { min((a) , (b)) , max((a) , (b)) }
#define flush cout.flush()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define endc "\n"
#define MOD 998244353
#define mod(x) (x) %= MOD
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

// #define int ll
 
ll gcd(ll a, ll b){
    while(true){
        if(a>b)
            swap(a,b);
        if (a == 0) 
            return b; 
        ll p = b % a  , q = a;
        a = p;
        b = q;
    }
}
 
ll powerMod(ll x,ll y){
    ll res = 1;
    x %= MOD;
    while(y > 0){
        if(y & 1)res = (res*x)%MOD;
        y = y >> 1;
        x = (x * x)%MOD;
    }
    return res%MOD;
}
 
string binary(ll s) {
    string res = "";
    while(s != 0) {
        res += (char)('0' + s % 2);
        s /= 2;
    }
    reverse(res.begin() , res.end());
    return res;
}


//  =========     /\       /|    |====/|
//      |        /  \       |    |   / |
//      |       /____\      |    |  /  |
//      |      /      \     |    | /   |
//  ========= /        \  =====  |/====|  
//  code

int32_t main(){
    init;
    ll n,s,i,j,k,l,p;
    cin >> n >> s;
    vector<ll> a(n);
    vector< vector<ll> >dp(n + 1 , vector<ll>(s + 1 , 0LL));

    for(auto &i : a)cin >> i;

    for(i = p = 0LL; i < n; i++){
        dp[i + 1] = dp[i];
        if(a[i] <= s)
            mod( dp[i + 1][a[i]] += i + 1LL );
        for(j = 0LL; j <= s - a[i]; j++){
            mod( dp[i + 1][j + a[i]] += dp[i][j] );
        }
        mod (p += dp[i + 1][s]);
    }
    cout << p << endc;
    return 0;
}