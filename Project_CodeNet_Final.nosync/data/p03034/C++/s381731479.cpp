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

int main() {
    int n;
    cin >> n;
    VL a(n);
    REP(i,n) a[i] = in();
    ll ans = 0;
    FOR(d,1,n){
        ll tmp = 0;
        set<int> st;
        REP(x,n){
            int i = d * x;
            int j = n - 1 - d * x;
            if (i >= n - 1) break;
            tmp += a[i] + a[j];
            if (j < d) break;
            if (st.count(i)) break;
            st.insert(i);
            if (st.count(j)) break;
            st.insert(j);
            chmax(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}
