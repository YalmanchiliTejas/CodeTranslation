#include <bits/stdc++.h>
using namespace std;

#define maxn 100002
#define FOR(i, l, r) for (int i=l; i<=r; ++i)
#define FORD(i, r, l) for (int i=r; i>=l; --i)
#define REP(i, r) for (int i=0; i<(int)r; ++i)
#define REPD(i, r) for (int i=(int)r-1; i>=0; --i)
#define fi first
#define se second
#define mk make_pair
#define nil NULL
#define y0 y902
#define y1 y232
#define x0 x92
#define x1 x899
#define next asdfa
#define sz size
#define Debug(X) {cerr << #X << " = " << X << '\n';}
#define PR(A, n) {cerr << #A << " = "; FOR(i, 1, n) cerr << A[i] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; REP(i, n) cerr << A[i] << ' '; cerr << '\n';}
typedef long long ll;
typedef double db;
typedef pair<db, db> dd;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 1e9;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n, d[maxn];
set<int> a[maxn];
priority_queue<ii, vector<ii>, greater<ii> > pq;

int main() {
    //freopen("bwtree.inp", "r", stdin);
    //freopen("", "w", stdout);
    //ios::sync_with_stdio(0); cin.tie(0);
    scanf("%d", &n);
    FOR(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        a[u].insert(v);
        a[v].insert(u);
    }
    FOR(u, 1, n) {
        int cnt = 0;
        for (set<int>::iterator it=a[u].begin(); it!=a[u].end(); ++it) {
            int v = *it;
            if (a[v].sz()==1) ++cnt;
        }
        if (cnt>1) {
            printf("First");
            return 0;
        }
    }
    FOR(i, 1, n) pq.push(ii(d[i]=a[i].sz(), i));
    while (pq.sz()) {
        ii u = pq.top(); pq.pop();
        if (d[u.se]!=u.fi) continue;
        if (d[u.se]==0) {
            printf("First\n");
            return 0;
        }
        int v = *a[u.se].begin();
        d[v] = -1;
        for (set<int>::iterator it=a[v].begin(); it!=a[v].end(); ++it) {
            a[*it].erase(a[*it].find(v));
            d[*it]--;
            if (*it!=u.se) pq.push(ii(d[*it], *it));
        }
    }
    printf("Second");
}

