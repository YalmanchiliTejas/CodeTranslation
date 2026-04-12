#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

ll n;
string s;
vl a;  // a[i] : s[i]が'o'なら0、'x'なら1 

void f(vl& v) {  // v[0],v[1]をもとにvの要素を埋める
    exrep(i, 1, n-2) {
        if(a[i] == v[i]) {
            v[i+1] = v[i-1];
        }
        else {
            v[i+1] = 1 - v[i-1];
        }
    }
}

bool check(vl& v) {  // fで埋めたvの要素が矛盾してないか調べる
    if(a[n-1] == v[n-1]) {
        if(v[n-2] != v[0]) {
            return false;
        }
    }
    else if(v[n-2] == v[0]) {
        return false;
    }
    if(a[0] == v[0]) {
        if(v[n-1] != v[1]) {
            return false;
        }
    }
    else if(v[n-1] == v[1]) {
        return false;
    }
    return true;
}

int main() {
    
    cin >> n >> s;  

    a.assign(n, 0);
    rep(i, n) {
        if(s[i] == 'x') {
            a[i] = 1;
        }
    } 

    vl v(n);  // v[i] : i匹目が羊なら0、狼なら1
    rep(x, 2) {
        rep(y, 2) {
            v[0] = x, v[1] = y;
            f(v);
            if(check(v)) {
                rep(i, n) {
                    if(v[i]) {
                        cout << 'W';
                    }
                    else {
                        cout << 'S';
                    }
                }
                cout << "\n";
                re0;
            }
        }
    }
    
    out(-1);
    re0;
}