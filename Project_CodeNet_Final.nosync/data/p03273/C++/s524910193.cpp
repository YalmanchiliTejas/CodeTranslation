#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const long double EPS = 1e-9;
const ll mod = 1e9 + 7;
const ll INF = 1e9;

#define rep(i, n) for(ll i = 0; i < n ; i++ )
#define For(i, a, b) for(ll i = (a); i < (b) ; i++ )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MAX_N = 100;

int main(void){
    ll H, W;
    string a[MAX_N];
    ll cnt_h[MAX_N], cnt_w[MAX_N];

    cin >> H >> W;

    rep(h, H) cin >> a[h];
    
    rep(w, W) cnt_w[w] = 0;
    rep(h, H) cnt_h[h] = 0;

    rep(w, W) rep(h, H) if (a[h][w] == '#') break; else if (h == H - 1) cnt_w[w] = 1; 
    rep(h, H) rep(w, W) if (a[h][w] == '#') break; else if (w == W - 1) cnt_h[h] = 1;

    rep(h, H){
        if (cnt_h[h] == 1) continue;
        rep(w, W){
            if (cnt_w[w] == 1) continue;
            cout << a[h][w];
        }
        cout << "" << endl;
    } 

    return 0;
}