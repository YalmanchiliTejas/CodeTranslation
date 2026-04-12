//--------------------------------------------------
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2,popcnt,fma")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")
//--------------------------------------------------
#include <bits/stdc++.h>
#include <chrono>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
#include <iomanip>
#include <numeric>
#include <time.h>
#include <ctime>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <stack>
#include <cstring>
//--------------------------------------------------
#define forn(i, n) for(int i = 0; i < n; i++)
#define forw(i, n) for(int i = n-1; i >= 0; --i)
#define forns(i, n, s) for(int i = s; i < n; i++)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
//----------------------------------------------------
using namespace std;
//----------------------------------------------------
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef vector<ll> lnum;
typedef complex<ld> comp;
//----------------------------------------------------
const ll mod = 1e9 + 7, mod2 = 998244353;
const ld eps = 1e-6;
const ll inf = 1e18;
const int base = 1e9;
const ld PI = 3.1415926;
//----------------------------------------------------
//#define endl '\n';
#ifdef MY_DEBUG
void deb(ld x) { cerr << x << endl; };
#else
void deb(ld x){};
#endif
//----------------------------------------------------
//----------------------------------------------------
bool used[2][3001][3001];
ll dp[2][3001][3001];
ll a[3000];
ll n;
//----------------------------------------------------
unsigned int bitcount(ull val) { return __builtin_popcount(val) + __builtin_popcount(val >> 32); }

void local() {
    freopen("test.in", "r", stdin);
}

void remote() {
}

void read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    forn(i, n) cin >> a[i];
}

ll cnt(uint tp, int l, int r){
    if(l > r)
        return 0;
    if(used[tp][l][r]) return dp[tp][l][r];
    used[tp][l][r] = true;
    if(tp == 0){
        dp[tp][l][r] = max(cnt(tp^1u, l+1, r) + a[l], cnt(tp^1u, l, r-1) + a[r]);
    }else{
        dp[tp][l][r] = min(cnt(tp^1u, l+1, r)-a[l], cnt(tp^1u, l, r-1) -a[r]);
    }

    return dp[tp][l][r];
}

int main() {
#ifdef MY_DEBUG
    local();
#else
    remote();
#endif
    read();

    cout << cnt(0, 0, n-1);

}