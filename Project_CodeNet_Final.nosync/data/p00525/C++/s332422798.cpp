#include<bits/stdc++.h>
const long long N = 2e5 + 5;
using namespace std;

typedef pair <long long, long long> ii;
typedef pair <ii, long long> iii;
vector <ii> vc;
vector <iii> mv;

long long w, h, n, x[2][N], y[2][N], a[20*N], pos[2][N], num, bit[N];
long long cnt, ver, root_ver[N], ans;
bool check[20*N];

struct {
    long long pset[N], numdsu;

    void init (long long n){
        for (long long i = 1; i <= n; i++) pset[i] = i;
        numdsu = n;
    }

    long long findset(long long i) {
        if (pset[i] != i) pset[i] = findset(pset[i]);
        return pset[i];
    }

    void unionset(long long i, long long j){
        if (findset(i) == findset(j)) return;
        pset[findset(i)] = findset(j);
        numdsu--;
    }
} dsu;

struct node {
    long long val, left, right, cnt;
} lv[20*N];

void init(long long l, long long r){
    long long nod = cnt;
    if (l != r){
        long long mid = (l + r) / 2;
        lv[nod].left  = ++cnt; init (l, mid);
        lv[nod].right = ++cnt; init (mid+1, r);
    }
}

void dolazy(long long k, long long l, long long r){
    if (lv[k].val == 0) return;
    if (l != r) {
        long long a = lv[k].left, b = lv[k].right;
        if (lv[a].val) {dsu.unionset(lv[a].val, lv[k].val);}
        if (lv[b].val) {dsu.unionset(lv[b].val, lv[k].val);}
        if (lv[a].cnt) lv[a].val = lv[k].val;
        if (lv[b].cnt) lv[b].val = lv[k].val;
        lv[k].val = 0;
    }
}

void update(long long k, long long l, long long r, long long pos, long long val){
    dolazy(k, l, r);
    if (l > pos || pos > r) return;
    if (l == r){
        lv[cnt].val = val;
        lv[cnt].cnt = (val != 0);
        return;
    }
    long long mid = (l + r) / 2; long long nod = cnt;
    if (pos > mid){
        lv[nod].left = lv[k].left;
        lv[nod].right = ++cnt;
        update(lv[k].right, mid+1, r, pos, val);
    }
    else{
        lv[nod].left = ++cnt;
        lv[nod].right = lv[k].right;
        update(lv[k].left, l, mid, pos, val);
    }
    lv[nod].cnt = lv[lv[nod].left].cnt + lv[lv[nod].right].cnt;
}

void update(long long pos, long long val){
    root_ver[++ver] = ++cnt;
    update(root_ver[ver-1], 1, num, pos, val);
}

void update (long long k, long long l, long long r, long long L, long long R, long long val){
    dolazy(k, l, r);
    if (l > R || L > r) return;
    if (L <= l && r <= R){
        if (lv[k].val) dsu.unionset(lv[k].val, val);
        if (lv[k].cnt) lv[k].val = val;
        return;
    }
    long long mid = (l + r) / 2;
    update(lv[k].left, l, mid, L, R, val); update(lv[k].right, mid+1, r, L, R, val);
}

void dfs(long long u){
    if (check[u]) return;
    check[u] = 1; a[u] = lv[u].val; long long v;
    v = lv[u].left;  dfs(v);
    if (a[u] && a[v]) {dsu.unionset(a[u], a[v]);}
    else a[u] = max(a[u], a[v]);
    v = lv[u].right; dfs(v);
    if (a[u] && a[v]) {dsu.unionset(a[u], a[v]);}
    else a[u] = max(a[u], a[v]);
}

void updatebit(long long i, long long val){
    while (i <= num) bit[i]+=val, i += i&(-i);
}

long long get(long long l, long long r){
    long long ans = 0; l--;
    while (r > 0) ans += bit[r], r -= r&(-r);
    while (l > 0) ans -= bit[l], l -= l&(-l);
    return ans;
}

void init(){
    cin >> w >> h >> n;
    for (long long i = 1; i <= n; i++) cin >> x[0][i] >> y[0][i] >> x[1][i] >> y[1][i];
    x[0][n+1] = 0; y[0][n+1] = 0; x[1][n+1] = w; y[1][n+1] = 0;
    x[0][n+2] = 0; y[0][n+2] = h; x[1][n+2] = w; y[1][n+2] = h;
    x[0][n+3] = 0; y[0][n+3] = 0; x[1][n+3] = 0; y[1][n+3] = h;
    x[0][n+4] = w; y[0][n+4] = 0; x[1][n+4] = w; y[1][n+4] = h;
    n += 4;
    for (long long i = 1; i <= n; i++){
        if (x[0][i] > x[1][i] || y[0][i] > y[1][i]){
            swap(x[0][i], x[1][i]);
            swap(y[0][i], y[1][i]);
        }
        if (x[0][i] != x[1][i]) {
            mv.push_back(iii(ii(x[0][i], -1), i));
            mv.push_back(iii(ii(x[1][i],  1), i));
            vc.push_back(ii(y[0][i], i));
        }
        else{
            mv.push_back(iii(ii(x[0][i],  0), i));
            vc.push_back(ii(y[0][i], i));
            vc.push_back(ii(y[1][i], i));
        }
    }
    sort (mv.begin(), mv.end());
    sort (vc.begin(), vc.end());
    dsu.init(n);
    ans = -n;
    for (long long i = 0; i < vc.size(); i++){
        if (i == 0 || (i > 0 && vc[i].first != vc[i-1].first)) num++;
        long long z = vc[i].second;
        if (pos[0][z]) pos[1][z] = num;
        else pos[0][z] = num;
    }
    root_ver[++ver] = ++cnt; init(1, num);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    for (long long i = 0; i < mv.size(); i++){
        long long z = mv[i].second, val = mv[i].first.first;

        if (val == x[0][z] && val == x[1][z]) update(root_ver[ver], 1, num, pos[0][z], pos[1][z], z);
        else if (val == x[0][z]) update(pos[0][z], z);
        else update(pos[0][z], 0);

        if (val == x[0][z] && val == x[1][z]) ans += get(pos[0][z], pos[1][z]);
        else if (val == x[0][z]) updatebit(pos[0][z], 1);
        else updatebit(pos[0][z], -1);
    }
    for (long long i = 1; i <= cnt; i++) if (lv[i].val) dfs(i);
    ans += dsu.numdsu;
    cout << ans << "\n";
}