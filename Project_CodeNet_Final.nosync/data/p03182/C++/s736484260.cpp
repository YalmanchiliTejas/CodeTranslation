#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tp;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;
typedef pair<LL, pii> plpii;
typedef pair<LD, LD> pdd;
typedef pair<LD, int> pdi;
typedef pair<LD, LL> pdl;
typedef pair<int, LD> pid;
typedef pair<LL, LD> pld;
const int mod = 1e9 + 7;
const int hf = 999983;
const int N = 1e6;

LL seg[4*200005], lazy[4*200005];

void push_down(int n, LL v){
    lazy[n+n] += v;
    lazy[n+n+1] += v;
}

void update(int n, int s, int e, int l, int r, LL v){
    if(lazy[n] != 0){
        seg[n] += lazy[n];
        if(s != e) push_down(n, lazy[n]);
        lazy[n] = 0;
    }
    if(s > r || l > e) return;
    if(l <= s && e <= r){
        seg[n] += v;
        if(s != e) push_down(n, v);
        return;
    }
    int mid = (s+e)/2;
    update(n+n, s, mid, l, r, v);
    update(n+n+1, mid+1, e, l, r, v);
    seg[n] = max(seg[n+n], seg[n+n+1]);
}

LL query(int n, int s, int e, int l, int r){
    if(lazy[n] != 0){
        seg[n] += lazy[n];
        if(s != e) push_down(n, lazy[n]);
        lazy[n] = 0;
    }
    if(s > r || l > e) return -1e18;
    if(l <= s && e <= r) return seg[n];
    int mid = (s+e)/2;
    return max(query(n+n, s, mid, l, r), query(n+n+1, mid+1, e, l, r));
}

vector<int> add[200005], del[200005];
LL dp[200005];
int l[200005], r[200005], a[200005];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d", &l[i], &r[i], &a[i]);
        add[l[i]].push_back(i);
        del[r[i]].push_back(i);
    }
    LL ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<add[i].size();j++){
            int idx = add[i][j];
            update(1, 0, n, 0, l[idx]-1, a[idx]);
        }
        dp[i] = query(1, 0, n, 0, i-1);
        update(1, 0, n, i, i, dp[i]);
        ans = max(ans, dp[i]);
        for(int j=0;j<del[i].size();j++){
            int idx = del[i][j];
            update(1, 0, n, 0, l[idx]-1, -a[idx]);
        }
    }
    printf("%lld\n", ans);
}