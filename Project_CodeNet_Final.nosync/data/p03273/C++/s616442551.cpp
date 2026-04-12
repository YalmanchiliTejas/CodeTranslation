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
#include <deque>
#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
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

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    REP(i,n) cin >> s[i];
    VI a(n), b(m);
    REP(i,n){
        bool ok = true;
        REP(j,m) if (s[i][j] == '#') ok = false;
        a[i] = ok;
    }
    REP(j,m){
        bool ok = true;
        REP(i,n) if (s[i][j] == '#') ok = false;
        b[j] = ok;
    }

    REP(i,n){
        if (a[i]) continue;
        REP(j,m) if (!b[j]) cout << s[i][j];
        cout << endl;
    }

    return 0;
}