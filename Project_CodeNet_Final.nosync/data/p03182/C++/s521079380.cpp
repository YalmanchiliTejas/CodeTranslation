#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

const int maxn = 2e5 + 5;

int n, m;

int l[maxn], r[maxn];
typedef long long LL;
LL a[maxn];
LL score[maxn];

LL maxv[maxn << 2];
LL addv[maxn << 2];
#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

void pushup(int o){
    maxv[o] = max(maxv[o*2],maxv[o*2+1]);
}

void pushdown(int o){
    if(addv[o]){
        addv[o*2] += addv[o];
        addv[o*2+1] += addv[o];
        maxv[o*2] += addv[o];
        maxv[o*2+1] += addv[o];
        addv[o] = 0;
    }
}

void build(int o, int l, int r){
    maxv[o] = 0;
    addv[o] = 0;
    if(l == r)
        return;
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
}

void update(int o, int l, int r, int ql, int qr, LL v){
    if(ql <= l && r <= qr){
        maxv[o] += v;
        addv[o] += v;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(ql <= mid)
        update(lson, ql, qr, v);
    if(qr > mid)
        update(rson, ql, qr, v);
    pushup(o);
}

LL querymax(int o, int l, int r, int ql, int qr){
    if(ql > qr)
        return 0;
    if(ql <= l && r <= qr){
        return maxv[o];
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(qr <= mid)
        return querymax(lson, ql, qr);
    if(ql > mid)
        return querymax(rson, ql, qr);
    return max(querymax(lson, ql, qr), querymax(rson, ql, qr));
}

vector<int> in[maxn], out[maxn];

LL dp[maxn];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        scanf("%d%d%lld", &l[i], &r[i], &a[i]);
        score[l[i]] += a[i];
        score[r[i] + 1] -= a[i];
        in[l[i]].push_back(i);
        out[r[i] + 1].push_back(i);
    }
    score[0] = 0;
    for(int i = 1;i <= n;i++){
        score[i] += score[i - 1];
    }
    for(int i = 1;i <= n;i++){
        for(auto id : out[i]){
            update(1, 1, n + 1, l[id] + 1, r[id] + 1, a[id]);
        }
        for(auto id : in[i]){
            update(1, 1, n + 1, l[id] + 1, r[id] + 1, -a[id]);
        }
        dp[i] = querymax(1, 1, n + 1, 1, i) + score[i];        
        update(1, 1, n + 1, i + 1, i + 1, dp[i]);
    }
    LL ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
