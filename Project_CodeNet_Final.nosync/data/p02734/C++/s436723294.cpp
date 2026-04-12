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
//const ll MOD = 1e9 + 7;
 
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
vector<ll> a;
ll memo[3300][3300][3];
ll MOD = 998244353;
ll rec(ll i, ll j, ll state){
    if(i == -1){
        if(j == 0 && (state == 0 || state == 1)){
            return 1;
        } else {
            return 0;
        }
    }

    if(memo[i][j][state] != -1) return memo[i][j][state];

    ll res = 0;
    if(state == 2){
        if(j - a[i] >= 0) res += rec(i - 1, j - a[i], 1);
        res %= MOD;
        res += rec(i - 1, j, 1);
        res %= MOD;
    }
    if(state == 1){
        if(j - a[i] >= 0) res += rec(i - 1, j - a[i], state);
        res %= MOD;
        res += rec(i - 1, j, 0);
        res %= MOD;
    }

    res += rec(i - 1, j, state);
    res %= MOD;

    return memo[i][j][state] = res;
} 
int main(void){
    ll n, s;
    cin >> n >> s;
    a.resize(n);
    rep(i, n) cin >> a[i];
    rep(i, 3300){
        rep(j, 3300){
            rep(k, 3){
                memo[i][j][k] = -1;
            }
        }
    }

    cout << rec(n - 1, s, 2) << endl;
}
