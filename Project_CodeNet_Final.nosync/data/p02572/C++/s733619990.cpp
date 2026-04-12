#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define enld endl //* missspell check
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
const long long MOD = 1000000007;


ll gcd (ll a, ll b){ return b == 0? a : gcd(b, a % b); }
ll lcm (ll a, ll b){ return a * (b / gcd(a, b));}

ll extgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

//* calculate a^-1 mod m
ll mod_inverse(ll a, ll m){
    ll x, y;
    extgcd(a, m, x, y);
    return(m + x%m) % m;
}

void solve(long long N, std::vector<long long> A){
    ll sum = 0, sum2 = 0;
    REP(i, N){
        sum = (sum + A[i]) % MOD;
        sum2 = (sum2 + (A[i]*A[i]) % MOD) % MOD;
    }
    ll ans = ( (sum * sum) % MOD - sum2) % MOD;
    if(ans < 0) ans += MOD;
    ll fac = mod_inverse(2, MOD);
    ans = (ans * fac) % MOD;
    cout<<ans<<endl;

}
int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
