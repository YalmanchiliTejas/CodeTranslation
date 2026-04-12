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

const ll MAX_N = 100000;

ll power_(ll a, ll power){
    ll value = 1;
    
    while(power != 0){
        if(power & 1) value = (value * a);
        a = (a * a);
        power = power >> 1;
    }
 
    return value;
}

ll f(ll N, ll X){
    ll ret;
    ll N2 = power_(2, N);
    ll aNm = 2 * N2 - 3;
    ll pNm = N2 - 1;
    
    if (X == 0) return 0;
    else if (N == 0) return 1;
    else if (X <= aNm + 1) ret = f(N - 1, X - 1);
    else ret = f(N - 1, X - aNm - 2) + 1 + pNm;

    return ret;
}

int main(void){
    ll N, X;
    ll answer = 1e9;
    cin >> N >> X;

    cout << f(N, X) << endl;

    return 0;
}