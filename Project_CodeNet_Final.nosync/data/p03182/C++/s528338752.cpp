// 以下のソースを勉強する.
// zscoder氏.
// https://atcoder.jp/contests/dp/submissions/3944823
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

map<pair<LL, LL>, LL> ma;

bool cmp(pair<pair<LL, LL>, LL> a, pair<pair<LL, LL>, LL> b){
    if(a.first.first != b.first.first)   return (a.first.first < b.first.first);
    if(a.first.second != b.first.second) return (a.first.second > b.first.second);
    return (a.second < b.second);
}

class LazySegmentTree{
private:
    int size_;
    vector<LL> v, lazy;
    void update(int a, int b, LL x, int k, int l, int r){
        push(k, l, r);
        if(r <= a || b <= l) return;
        if(a <= l && r <= b){
            lazy[k] = x;
            push(k, l, r);
        }else{
            update(a, b, x, k * 2,                l, (l + r) >> 1);
            update(a, b, x, k * 2 + 1, (l + r) >> 1,            r);
            v[k] = merge(v[k * 2], v[k * 2 + 1]);
        }
    }
    LL query(int a, int b, int k, int l, int r){
        push(k, l, r);
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return v[k];
        LL lc = query(a, b, k * 2,                l, (l + r) >> 1);
        LL rc = query(a, b, k * 2 + 1, (l + r) >> 1,            r);
        return merge(lc, rc);
    }

public:
    LazySegmentTree() : v(vector<LL>()), lazy(vector<LL>()) {};
    LazySegmentTree(int n){
        for(size_ = 1; size_ < n;) size_ <<= 1;
        v.resize(size_ * 4,0);
        lazy.resize(size_ * 4,0);
    }
    inline void push(int k, int l, int r){
        if(lazy[k] != 0){
            v[k] += lazy[k];
            if(r - l > 1){
                lazy[k * 2]     += lazy[k];
                lazy[k * 2 + 1] += lazy[k];
            }
            lazy[k] = 0;
        }
    }
    inline LL merge(LL x, LL y){
        return min(x, y);
    }
    inline void update(int l, int r, LL x){
        update(l, r, x, 1, 0, size_);
    }
    inline LL query(int l, int r){
        return query(l, r, 1, 0, size_);
    }
};

vector<pair<LL, LL>> V[222222];
LL dp[222222];

int main(){
    
    // 1. 入力情報取得.
    int N, M;
    scanf("%d %d", &N, &M);
    LL sum = 0;
    for(int i = 0; i < M; i++){
        int l, r;
        LL w;
        scanf("%d %d %lld", &l, &r, &w);
        ma[{l, r}] += w;
        sum += w;
    }
    
    // 2. dp更新.
    vector<pair<pair<LL, LL>, LL>> vec;
    for(auto X : ma) vec.push_back(X);
    sort(vec.begin(), vec.end(), cmp);
    for(auto X : vec) V[X.first.second].push_back({X.first.first, X.second});
    LazySegmentTree st(N + 5);
    for(int i = 1; i <= N + 1; i++){
        dp[i] = st.query(0, i);
        for(pair<LL, LL> v : V[i]) st.update(0, v.first, v.second);
        st.update(i, i + 1, dp[i]);
    }
    
    // 3. 出力.
    printf("%lld\n", sum - dp[N + 1]);
    return 0;
    
}