#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<P,ll> PP;

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
    ll e=-INF;
 
public:
    ll F(ll a,ll b){
        return max(a,b);
    }

    void init(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1,e);
        lazy.resize(2*n-1,0);
 
        rep(i,sz) node[i+n-1] = v[i];
        per(i,n-1) node[i] = F(node[i*2+1],node[i*2+2]);
    }

    void tell(){
        rep(i,node.size()) cout << node[i] << endl;
    }
 
    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] ;//区間にxを足したら子の区間Fはどうなるか
                lazy[2*k+2] += lazy[k] ;
            }
            lazy[k] = 0;
        }
    }
 
    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;//区間にxを足したら区間のFはどうなるか
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = F(node[2*k+1],node[2*k+2]);
        }
    }
 
    ll get(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return e;
        if(a <= l && r <= b) return node[k];
        ll vl = get(a, b, 2*k+1, l, (l+r)/2);
        ll vr = get(a, b, 2*k+2, (l+r)/2, r);
        return F(vl,vr);
    }
};

int n,m;
vector<PP> seg;

void solve(){

    cin >> n >> m;
    vector<ll> d(n+2,0);
    rep(i,m){
        int l,r;ll a;
        cin >> l >> r >> a;
        seg.push_back(PP(P(l,r),a));
    }
    stable_sort(seg.begin(),seg.end());
    LazySegmentTree dp;dp.init(d);
    priority_queue<PP,vector<PP>,greater<PP>> que;
    //rep(i,m) cout << seg[i].first.first << " " << seg[i].first.second << " " << seg[i].second << endl;
    int k=0;
    rep(i,n+1){
        while (seg[k].first.first==i+1){
            //cout << seg[k].second << endl;
            dp.add(0,i+1,seg[k].second);
            que.push(PP(P(seg[k].first.second,seg[k].first.first),seg[k].second));
            k+=1;
        }
        if (!que.empty()){
            //cout << que.top().first.first << endl;
            while (que.top().first.first==i){
                ll a=que.top().second;int l=que.top().first.second;que.pop();
                dp.add(0,l,-a);
                if (que.empty()) break;
            }
        }
        // rep(i,n+2){
        //     cout << dp.get(i,i+1) << " ";
        // }
        //cout << "" << endl;
        dp.add(i+1,i+2,dp.get(0,i+1));
        
    }
    cout << dp.get(0,n+2) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}