#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <iomanip>
#include <map>
#include <queue>
#include <list>

#define REP(i, n ,N) for(ll i = (n); i < (N); i++)
//#define RREP(i, n ,N) for(ll i = (N-1); i >= (n); i--)
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl

#define vint vector<int>
#define vll vector<ll>

#define INF 1e9
#define PI 3.14159265359

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using namespace std;
typedef long long  ll;

const long long MOD = 1e9+7;


int main(){
    ll n;
    cin >> n;
    vll a(n);
    ll tmp;
    ll sum = 0;
    REP(i, 0, n){
        cin >> a[i];
        sum += a[i];
        sum %= MOD;
    }

//    ll sum = accumulate(a.begin(), a.end(), 0);
    ll ans = 0;

    REP(i, 0, n){
        sum -= a[i];
        if(sum < 0) sum += MOD;
        ans += ((sum % MOD) * a[i]) % MOD;
    }

    p(ans%MOD);

    return 0;
}
