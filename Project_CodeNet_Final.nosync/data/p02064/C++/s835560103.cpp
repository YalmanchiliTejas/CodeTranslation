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
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef vector<double> VD;
typedef vector<VD> VVD;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

int ask(int u, int v){
    cout << "? " << u + 1 << " " << v + 1 << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    int n, s, t;
    cin >> n >> s >> t;
    s--;
    t--;
    int d = ask(s, t);
    vector<P> cands;
    REP(i,n){
        if (i == s || i == t) continue;
        int d1 = ask(i, s), d2 = ask(i, t);
        if (d1 + d2 == d){
            cands.push_back(P(d1, i));
        }
    }
    sort(ALL(cands));
    VI ans({s});
    int x = 0;
    for (P p : cands){
        if (x + ask(ans.back(), p.second) == p.first){
            ans.push_back(p.second);
            x = p.first;
        }
    }
    ans.push_back(t);
    cout << "!";
    for (int x : ans) cout << " " << x + 1;
    cout << endl;

    return 0;
}

