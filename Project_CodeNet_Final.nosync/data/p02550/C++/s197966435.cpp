/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.09.20 03:08:54
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    ll n,x,m;cin >> n >> x >> m;
    vector<vector<int>> to(35,vector<int>(m));
    vector<vector<ll>> doubling(35,vector<ll>(m));
    for (ll i = 0; i < m; i++) {
        to[0][i] = i*i%m;
        doubling[0][i] = i*i%m;
    }
    for (int i = 0; i < 33; i++) {
        for (int j = 0; j < m; j++) {
            to[i+1][j] = to[i][to[i][j]];
            doubling[i+1][j] = doubling[i][j] + doubling[i][to[i][j]];
        }
    }
    ll ans = 0;
    int now = x;
    n--;
    for (int i = 0; i < 35; i++) {
        if ((1LL<<i) & n) {
            
            ans += doubling[i][now];
            now = to[i][now];
        }
    }
    cout << ans + x << endl;
    return 0;
}