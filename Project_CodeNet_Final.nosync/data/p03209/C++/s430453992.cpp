#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll n, x;
vector<ll> a(51, 1), p(51, 1);
ll rec(ll n, ll x) {
    if (x <= 0) return 0;
    if (n == 0) return 1;
    else if (x <= 1 + a[n-1]) return rec(n-1, x-1);
    else return p[n-1] + 1 + rec(n-1, x-2-a[n-1]);
}

int main() {
    cin >> n >> x;
    rep(i, n) {
        a[i+1] = 2 * a[i] + 3;
        p[i+1] = 2 * p[i] + 1;
    }
    cout << rec(n, x) << endl;
}