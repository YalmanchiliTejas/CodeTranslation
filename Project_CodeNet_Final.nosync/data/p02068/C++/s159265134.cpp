#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

VL primes(int n){
    vector<bool> a(n+1, 1);
    VL p;
    FOR(x,2,n){
        if (!a[x]) continue;
        p.push_back(x);
        for (int y = 2 * x; y <= n; y += x) a[y] = 0;
    }
    return p;
}

int main() {
    int n;
    cin >> n;
    VL a(n);
    REP(i,n) a[i] = in();
    VL ps = primes(5e4);
    set<ll> st;
    REP(i,n){
        ll x = a[i];
        for (ll p : ps){
            if (x % p == 0){
                st.insert(p);
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) st.insert(x);
    }
    ll ans = 0;
    for (ll p : st){
        ll sum = 0;
        REP(i,n) if (a[i] % p == 0) sum += a[i];
        chmax(ans, sum);
    }
    cout << ans << endl;
    return 0;
}

