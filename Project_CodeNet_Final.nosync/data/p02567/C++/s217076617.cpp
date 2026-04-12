#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

using namespace atcoder;

int op(int a,int b){
    return max(a,b);
}

int e(){
    return -1;
}

int target;

bool f(int v){
    return v<target;
}

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    segtree<int,op,e> seg(a);
    
    rep(i,q){
        int t;
        cin >> t;
        if(t==1){
            int x,v;
            cin >> x >> v;
            x--;
            seg.set(x,v);
        }
        if(t==2){
            int l,r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l,r) << endl;
        }
        if(t==3){
            int x,v;
            cin >> x >> v;
            x--;
            target=v;
            cout << seg.max_right<f>(x)+1 << endl;
        }
    }
    return 0;
}