#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

bool check(VL &a, int n, ll x){
    if (x < 0) return false;
    ll s = 0;
    REP(i,n){
        s += (a[i] + x + 1) / (n + 1);
    }
    // cout << x << " " << s << endl;
    return s <= x;
}

int main(void){
    int n;
    cin >> n;
    VL a(n);
    REP(i,n) cin >> a[i];

    sort(ALL(a));
    if (a[n-1] <= n-1){
        cout << 0 << endl;
        return 0;
    }

    ll ok = 1e18, ng = 0;
    while (ok - ng > 1){
        ll mi = (ok + ng) / 2;
        if (check(a, n, mi)) ok = mi;
        else ng = mi;
    }

    for (ll i = ok-100000; i <= ok; i++){
        if (check(a, n, i)){
            ok = i;
            break;
        }
    }

    cout << ok << endl;
    return 0;
}
