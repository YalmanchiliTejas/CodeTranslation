/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>
#include <cassert>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 62;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll conbinationMemo[100][100];

void cmemoInit(){
    rep(i, 100){
        rep(j, 100){
            conbinationMemo[i][j] = -1;
        }
    }
}
 
ll nCr(ll n, ll r){
    if(conbinationMemo[n][r] != -1) return conbinationMemo[n][r];
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return conbinationMemo[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
//-----------------------ここから-----------
ll n;
vector<ll> a;
ll memo[200100][5][5];
ll rec(ll i, ll j, ll k){
    if(i <= 0 && j == 0 && k == 0) return 0;
    if(i <= 0) return -INF;
    if(memo[i][j][k] != -INF) return memo[i][j][k];

    ll res = -INF;
    if(k > 0) res = max(res, rec(i - 4, j, k - 1) + a[i - 4]);
    if(j > 0) res = max(res, rec(i - 3, j - 1, k) + a[i - 3]);
    res = max(res, rec(i - 2, j, k) + a[i - 2]);

    return memo[i][j][k]  = res; 
}
int main(void){
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];

    vector<ll> e, o;
    e.push_back(0);
    o.push_back(0);
 
    for(int i = 0; i < n; i += 2){
        e.push_back(e.back() + a[i]);
    }
    for(int i = 1; i < n; i += 2){
        o.push_back(o.back() + a[i]);
    }

    
    if(n % 2 == 0){
        ll ans = -INF;
        ans = max(e.back(), o.back());
        for(int i = 0; i <= n / 2; i++){
            ans = max(ans, o[n / 2] - o[i] + e[i]);
        }
        cout << ans << endl;
    } else {
        rep(i, 200100){
            rep(j, 5){
                rep(k, 5){
                    memo[i][j][k] = -INF;
                }
            }
        }

        cout << max(rec(n + 1, 2, 0), rec(n + 1, 0, 1)) << endl;
    }
}
