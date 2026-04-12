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

int main(void){
    ll A, B, C, X, Y;
    ll a, b;
    ll answer = MAX_N * 10000;

    cin >> A >> B >> C >> X >> Y;

    rep(c, 2 * max(X, Y) + 1){
        a = max(ll(0), X - c / 2);
        b = max(ll(0), Y - c / 2);
        answer = min(a * A + b * B + c * C, answer);
        //cout << a << " " << b << " " << c << " " << answer << endl;
    }

    cout << answer << endl;

    return 0;
}