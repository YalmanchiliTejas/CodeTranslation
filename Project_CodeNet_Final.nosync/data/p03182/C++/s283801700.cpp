#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

const int MAXN = 2e5 + 5;
const int MOD = 998244353; //1e9 + 7;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second 
#define FAIL0 {cout << "0\n"; return 0;}
#define FAIL1 {cout << "-1\n"; return 0;}
#define FAILNO {cout << "NO\n"; return 0;}

int N, M;
vector<pair<int,pair<int,int>>> A[MAXN];
vector<pair<int,pair<int,int>>> B[MAXN];

LL val[MAXN*4], lz[MAXN*4], mx[MAXN*4];

void build(int node, int left, int right) {
    if (left == right) {
        mx[node] = 0;//
        lz[node] = 0;//
        return;
    }

    int m = (left + right) / 2;
    build(node*2, left, m);
    build(node*2 + 1, m+1, right);

    mx[node] = max(mx[node*2], mx[node*2+1]);
}

void push(int node, int left, int right) {
    mx[node] += lz[node];
    if (left != right) {
        lz[node*2]   += lz[node];
        lz[node*2+1] += lz[node];
    }

    lz[node] = 0;
}

void update(int node, int left, int right, int l, int r, LL newval) {
    push(node, left, right);
    if (r < l) return;
    if (r < left || right < l) return;

    if (l <= left && right <= r) {
        lz[node] += newval;
        push(node, left, right);
        return;
    }

    int m = (left + right) / 2;
    update(node*2, left, m, l, min(m, r), newval);
    update(node*2+1, m+1, right, max(m+1,l), r, newval);

    mx[node] = max(mx[node*2],mx[node*2+1]);
}

LL query(int node, int left, int right, int l, int r) {
    push(node, left, right);
    if (r < l) return -1e9;
    if (r < left || right < l) -1e9;

    if (l <= left && right <= r) return mx[node];

    int m = (left + right) / 2;
    return max(query(node*2, left, m, l, min(m,r)), 
               query(node*2+1, m+1, right, max(m+1,l), r));
}

int main(int argc, char **argv) {
#ifdef OJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int l,r,a;
        cin >> l >> r >> a;
        A[l].pb({a,{l,r}});
        B[r+1].pb({a,{l,r}});
    }

    build(1,0,N);
    LL ans = 0;
    LL cur = 0;

    for (int i = 1; i <= N+1; i++) {
        for (auto a: A[i]) cur += a.fi;
        for (auto b: B[i]) {
            cur -= b.fi;
            int l = b.se.fi;
            int r = b.se.se;
            update(1,0,N,l,r,b.fi);
        }

        LL m = query(1,0,N,0,i-1);
        ans = max(ans, m + cur);
        
        update(1,0,N,i,i,m);
    }

    cout << ans << endl;
    return 0;
}
