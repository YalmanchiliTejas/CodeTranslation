// C++ includes
#include <bits/stdc++.h>
// 俳句
using namespace std;

// alias templates
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

// alias declaration
using ll = long long;
using str = string;

using vll = V<ll>;
using vvll = V<vll>;
using vs = V<str>;

// loops
#define FOR(i, a, b)  for (ll i = (a); i <= (ll)(b); i++) // [a,b]
#define rFOR(i, a, b) for (ll i = (b); i >= (ll)(a); i--) // [b,a]
#define REP(i, a) FOR((i), 0, (ll)(a)-1) // [0,a-1]

// for debug
#define dbg(a) cerr << "  " << (#a) << ": " << (a) << "\n";

// procon common constants
const ll MOD_BIG = 1e9 + 7;

int main(void){
    string s;
    cin >> s;
    if(s=="AAA" || s=="BBB"){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}