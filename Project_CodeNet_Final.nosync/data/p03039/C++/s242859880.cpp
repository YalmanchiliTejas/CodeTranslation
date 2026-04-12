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
ll factorial[2010000];
ll invfactorial[2010000];

ll extGCD(ll a, ll b, ll &x, ll &y){
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
 
	ll d = extGCD(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
ll nCrM(ll n, ll r){
	ll ret = factorial[n];
	ret *= invfactorial[n - r];
	ret %= MOD;
	ret *= invfactorial[r];
	ret %= MOD; 
	return ret;
}

int main(void){
    factorial[0] = 1;
    for (int i = 1; i < 2010000; i++){
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    for (int i = 0; i < 2010000; i++){
        ll x, y;
        ll g = extGCD(factorial[i], MOD, x, y);
        while (x < 0) x += MOD;
        x %= MOD;
        invfactorial[i] = x;
    }
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for(ll i = n - 1; i >= 1; i--){
        ll tmpans = 0;
        tmpans += i * (n - i);
        tmpans %= MOD;
        tmpans *= nCrM(n * m - 2, k - 2);
        tmpans %= MOD;
        tmpans *= m * m;
        tmpans %= MOD;
        ans += tmpans;
        ans %= MOD;
    }



    for(ll i = m - 1; i >= 1; i--){
        ll tmpans = 0;
        tmpans += i * (m - i);
        tmpans %= MOD;
        tmpans *= nCrM(n * m - 2, k - 2);
        tmpans %= MOD;
        tmpans *= n * n;
        tmpans %= MOD;
        ans += tmpans;
        ans %= MOD;
    }

    cout << ans << endl;


}
