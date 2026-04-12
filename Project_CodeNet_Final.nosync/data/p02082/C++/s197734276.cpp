#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define sz(x) int(x.size())

typedef long long ll;

using namespace std;

static const int MAX = 100001;

/******* c++14 don't include *******/

template<typename T>
T gcd(T a, T b){if( b == 0)return a; return gcd(b, a%b); }
template<typename T>
T lcm(T a, T b){return a*b/gcd(a,b); }

/*******                      *******/

int main(int argc, const char * argv[]) {
    // input from txt
    /////////
    //write//
    /////////
    
    ll s, t;
    cin >> s >> t;
    ll p, q, m;
    cin >> p >> q >> m;
    ll y;
    cin >> y;
    
    ll a = 0;
    rep(i, 100000000){
        if(i)a = (a * p + q) % m;
        y ^= a;
    }
    
    cout << y << endl;
    
    
    return 0;
}

