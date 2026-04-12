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

const int INF = 1e8;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i,h) cin >> s[i];
    P pma(-INF, -INF), pmi(INF, INF), nma(-INF, INF), nmi(INF, -INF);
    REP(i,h) REP(j,w){
        if (s[i][j] != 'B') continue;
        if (i + j > pma.first + pma.second) pma = P(i, j);
        if (i + j < pmi.first + pmi.second) pmi = P(i, j);
        if (i - j > nma.first - nma.second) nma = P(i, j);
        if (i - j < nmi.first - nmi.second) nmi = P(i, j);
    }
    int ans = 0;
    REP(i,h) REP(j,w){
        if (s[i][j] != 'B') continue;
        chmax(ans, abs(i - pma.first) + abs(j - pma.second));
        chmax(ans, abs(i - pmi.first) + abs(j - pmi.second));
        chmax(ans, abs(i - nma.first) + abs(j - nma.second));
        chmax(ans, abs(i - nma.first) + abs(j - nma.second));
    }
    cout << ans << endl;

    return 0;
}

