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

struct SegmentTree{
    private:
        int n;
        vector<ll> node; //セグ木の持つデータの型を入力
        ll e = 0; //単位元
    public:
        ll F(ll a,ll b){
            return max(a,b);//二項演算
        }

        void init(vector<ll> v) {
            int sz = v.size();
            n = 1; while(n < sz) n *= 2;
            node.resize(2*n-1, e);

            rep(i,sz) node[i+n-1] = v[i];
            per(i,n-1) node[i] = F(node[2*i+1], node[2*i+2]);

            //rep(i,2*n-1) cout << node[i] << endl;
        }

        void update(int x,ll val){
            x += n-1;
            node[x] = val;
            while(x > 0) {
                x =(x-1)/2;
                node[x]=F(node[2*x+1],node[2*x+2]);
            }
        
        }

        ll get(int a, int b, int k=0, int l=0, int r=-1) {
            if(r < 0) r = n;
            if(r <= a || b <= l) return e;
            if(a <= l && r <= b) return node[k];

            ll vl = get(a, b, 2*k+1, l, (l+r)/2);
            ll vr = get(a, b, 2*k+2, (l+r)/2, r);
            return F(vl, vr);
        }
};

int n;
vector<ll> as,as_,bs;


void solve(){
    cin >> n;
    rep(i,n){
        ll a;
        cin >> a;
        as.push_back(a); 
        as_.push_back(a);
    }
    sort(as_.begin(),as_.end());
    rep(i,n){
        bs.push_back(lower_bound(as_.begin(),as_.end(),as[i])-as_.begin());
        //cout << bs[i] << endl;
    }
    ll m=as_.size();
    vector<ll> S;
    S.resize(m,0);
    SegmentTree s;s.init(S);
    rep(i,n){
        ll k=s.get(bs[i],m);
        s.update(bs[i],k+1);
    }
    ll ans=0;
    rep(i,m){
        ans=max(ans,s.get(i,i+1));
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}