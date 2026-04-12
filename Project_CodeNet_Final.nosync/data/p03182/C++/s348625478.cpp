#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+100;
struct Segment_Tree{
    ll min_val[maxn*4];
    ll lzy[maxn*4];
    void up(int x){
        min_val[x] = min(min_val[x<<1],min_val[x<<1|1]);
    }
    void down(int x){
        min_val[x<<1] += lzy[x];
        min_val[x<<1|1] += lzy[x];
        lzy[x<<1] += lzy[x];
        lzy[x<<1|1] += lzy[x];
        lzy[x] = 0;
    }
    void update(int x,int l,int r,int L,int R,ll val){
        if (l > R || L > r)return;
        if (L <= l && r <= R){
            min_val[x] += val;
            lzy[x] += val;
            return;
        }
        int mid = l + r >> 1;
        down(x);
        update(x<<1,l,mid,L,R,val);
        update(x<<1|1,mid+1,r,L,R,val);
        up(x);
    }
    ll query_min(int x,int l,int r,int L,int R){
        if (l > R || L > r)return LLONG_MAX;
        if (L <= l && r <= R)return min_val[x];
        int mid = l + r >> 1;
        down(x);
        return min(query_min(x<<1,l,mid,L,R),query_min(x<<1|1,mid+1,r,L,R));
    }
}segtree;
vector<pair<int,ll> > a[maxn];
int n,m;
ll dp[maxn][2];
int main(){
    scanf("%d%d",&n,&m);
    ll sum = 0;
    for (int i=0;i<m;i++){
        int l,r,a;
        scanf("%d%d%d",&l,&r,&a);
        sum += a;
        ::a[r].push_back({l,a});
    }
    for (int i=1;i<=n;i++){
        for (pair<int,ll> ai : a[i]){
            segtree.update(1,0,n,0,ai.first-1,ai.second);
        }
        dp[i][1] = min(dp[i-1][1],dp[i-1][0]);
        dp[i][0] = segtree.query_min(1,0,n,0,i-1);
        segtree.update(1,0,n,i,i,dp[i][1]);
    }
    cout<< sum - min(dp[n][0],dp[n][1]);
    return 0;
}
