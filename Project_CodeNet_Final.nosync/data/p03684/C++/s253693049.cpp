//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 100005
#define MOD 1000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct point {int x, y, id;};
bool cmpX(const point &a, const point &b) {return (a.x < b.x);}
bool cmpY(const point &a, const point &b) {return (a.y < b.y);}

struct edge {int u, v, w;};
bool cmpW(const edge &a, const edge &b) {return (a.w < b.w);}

struct UFDS {
private: vector<int> pset; int n;
public:
    UFDS(int n): n(n) {
        pset.resize(n);
        fto(i, 0, n-1) pset[i] = i;
    }
    int findSet(int i) {return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);}
    bool unionSet(int i, int j) {
        int p = findSet(i), q = findSet(j);
        if (p == q) return false;
        pset[p] = q;
        return true;
    }
};

int main () {
    int n; scanf("%d", &n);
    vector<edge> e;
    point p[n];
    fto(i, 0, n-1) scanf("%d%d", &p[i].x, &p[i].y), p[i].id = i;

    sort(p, p+n, cmpX);
    fto(i, 0, n-2) e.pb({p[i].id, p[i+1].id, p[i+1].x-p[i].x});
    sort(p, p+n, cmpY);
    fto(i, 0, n-2) e.pb({p[i].id, p[i+1].id, p[i+1].y-p[i].y});

    sort(e.begin(), e.end(), cmpW);

    UFDS s(n);
    int ans = 0;
    for (edge p: e) {
//        printf("%d %d %d\n", p.u, p.v, p.w);
        if (s.unionSet(p.u, p.v)) ans += p.w;
    }
    printf("%d", ans);

    return 0;
}
