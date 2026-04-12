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

int main(void){
    ll X;
    
    cin >> X;
    
    if (X == 3 || X == 5 || X == 7) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}