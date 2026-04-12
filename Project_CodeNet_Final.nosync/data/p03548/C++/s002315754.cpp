#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define for(i, a, b) for(ll (i)=a;(i)<(b);++(i))
#define rep(i, n)    for(i, 0, n)
#define sz(x)        ((ll)(x).size())
#define inf          1<<25

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};

int main() {
    ll x, y, z;
    cin >> x >> y >> z;
    
    ll l = 0;
    ll r = x;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        
        if (m * y + (m + 1) * z <= x) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
}