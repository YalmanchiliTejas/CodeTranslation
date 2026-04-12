#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e15;

ll n, m;
ll l, r, a;
vector<pll> Interval[220000];

struct Seg{
    vector<ll> sum;
    vector<ll> mx;
    Seg(){
        sum.resize(1 << 19, 0);
        mx.resize(1 << 19, 0);
    }

    void add_val(ll l, ll r, ll val, ll bottom = 0, ll top = (1 << 18), ll pos = 1){
        if(l <= bottom && top <= r){
            sum[pos] += val; //区間加算
            return;
        }
        if(r <= bottom || top <= l){
            return;
        }
        ll mid = (bottom + top) / 2;
        add_val(l, r, val, bottom, mid, pos * 2);
        add_val(l, r, val, mid, top, pos * 2 + 1);
        mx[pos] = max(mx[pos*2] + sum[pos*2], mx[pos*2+1] + sum[pos*2+1]); //最大値を更新
    }

    ll max_val(ll l, ll r, ll bottom = 0, ll top = 1 << 18, ll pos = 1){
        if(l <= bottom && top <= r){
            return sum[pos] + mx[pos];
        }
        if(r <= bottom || top <= l){
            return -INF;
        }
        ll mid = (bottom + top) / 2;
        return max(max_val(l, r, bottom, mid, pos * 2),
                   max_val(l, r, mid, top, pos * 2 + 1)) + sum[pos];
    }    
};

int main(){
    cin >> n >> m;
    for(ll i = 0;i < m;i++){
        cin >> l >> r >> a;
        Interval[r].push_back(pll(l, a));
    }
    Seg seg;
    for(ll i = 1;i <= n;i++){
        ll mx = seg.max_val(0,i);
        seg.add_val(i, i+1, mx);
        for(auto p: Interval[i]){//iが区間の右端になるものを見ていく
            ll l = p.first;
            ll a = p.second;
            seg.add_val(l, i+1, a);
        }
    }

    cout << seg.max_val(0,n+1) << endl;
    
    return 0;
}
