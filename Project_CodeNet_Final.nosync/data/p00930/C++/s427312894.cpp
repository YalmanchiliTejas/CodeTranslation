#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)

#define sz(x) (int) x.size()
#define pb push_back
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x))
#define un(x) x.erase(unique(all(x)), x.end())

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define eps 1e-9
#define OK cerr << "ok\n"
#define DB(x) cerr << #x << " = " << x << endl

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;

inline int setBit(int N, int pos) { return N=N | (1<<pos); }
inline int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


const int MAX = 300005, INF = 100000000;
int n, q, cum[MAX];
char str[MAX];
set <int> closeList;
struct data {
    int mn, prop;
} tree[MAX*4];

void init(int node, int beg, int endd) {
    if(beg == endd) {
        tree[node] = { cum[beg], 0 };
        return;
    }

    int left = node << 1;
    int right = left + 1;
    int mid = (beg+endd) >> 1;

    init(left, beg, mid);
    init(right, mid+1, endd);

    tree[node].mn = min(tree[left].mn, tree[right].mn);
}

inline void pushDown(int node, int left, int right) {
    tree[left].mn += tree[node].prop;
    tree[right].mn += tree[node].prop;
    tree[left].prop += tree[node].prop;
    tree[right].prop += tree[node].prop;
    tree[node].prop = 0;
}

void update(int node, int beg, int endd, int x, int y, int val) {
    if(x > y) return;
    if(beg == x && endd == y) {
        tree[node].mn += val;
        tree[node].prop += val;
        return;
    }

    int left = node << 1;
    int right = left + 1;
    int mid = (beg+endd) >> 1;

    if(tree[node].prop) pushDown(node, left, right);

    if(x <= min(y, mid)) update(left, beg, mid, x, min(y, mid), val);
    if(max(x, mid+1) <= y) update(right, mid+1, endd, max(x, mid+1), y, val);

    tree[node].mn = min(tree[left].mn, tree[right].mn);
}

int query(int node, int beg, int endd, int x, int y) {
    if(x > y) return INF;
    if(beg == x && endd == y) return tree[node].mn;

    int left = node << 1;
    int right = left + 1;
    int mid = (beg+endd) >> 1;

    if(tree[node].prop) pushDown(node, left, right);

    int l = (x <= min(y, mid))? query(left, beg, mid, x, min(y, mid)) : INF;
    int r = (max(x, mid+1) <= y)? query(right, mid+1, endd, max(x, mid+1), y) : INF;

    return min(l, r);
}

inline int bs(int high) {
    int low=1, mid, ret=high, ub=high;
    while(low <= high) {
        mid = (low+high) >> 1;
        if(query(1, 1, n, mid, ub) >= 2) {
            ret = min(ret, mid);
            high = mid-1;
        }
        else low = mid+1;
    }
    return ret;
}

inline int query(int idx) {
    int ret = idx;
    if(str[idx] == '(') { /// open to close
        str[idx] = ')';
        closeList.insert(idx);
        update(1, 1, n, idx, n, -2);
        ret = *closeList.begin();
        str[ret] = '(';
        closeList.erase(ret);
        update(1, 1, n, ret, n, +2);
        return ret;
    }
    else { /// close to open
        str[idx] = '(';
        closeList.erase(idx);
        update(1, 1, n, idx, n, +2);
        ret = bs(idx);
        str[ret] = ')';
        closeList.insert(ret);
        update(1, 1, n, ret, n, -2);
        return ret;
    }
}

int main() {
//    assert(freopen("in.txt","r",stdin));
//    assert(freopen("out.txt","w",stdout));

    int i, idx;

    sdii(n, q);
    sds(str+1);
    repl(i, n) {
        if(str[i] == '(') cum[i] = 1;
        else {
            cum[i] = -1;
            closeList.insert(i);
        }
        cum[i] += cum[i-1];
    }
    init(1, 1, n);
    while(q--) {
        sdi(idx);
        pfi(query(idx));
    }

    return 0;
}

