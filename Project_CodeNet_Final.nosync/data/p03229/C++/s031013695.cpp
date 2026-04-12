#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    sort(ALL(A));
    int h = 1, t = N-1;

    // list<ll> lst;
    // lst.push_front(A[0]);

    ll ans = 0;
    ll lst1 = A[0], lst2 = A[0];
    REP(i, N-1) {
        const ll a = abs(lst1 - A[h]);
        ll b = abs(lst1 - A[t]);
        ll c = abs(lst2 - A[h]);
        ll d = abs(lst2 - A[t]);
        ll m = max(max(a, b), max(c, d));
        if(m == a) {
            lst1 = A[h++];
        } else if(m == b) {
            lst1 = A[t--];
        } else if (m == c) {
            lst2 = A[h++];
        } else {
            lst2 = A[t--];
        }
        ans += m;
    }

    cout << ans << endl;

    return 0;
}