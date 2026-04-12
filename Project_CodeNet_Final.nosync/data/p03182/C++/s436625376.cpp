#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define td(v) v.begin(),v.end()
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define re(v) {for(auto &_re : v) cin >> _re;}
#define rre(v){for(auto &_re : v) for(auto &_rre : _re) cin >> _rre;}
#define pr(v) {for(auto _pr : v) cout << _pr << " "; cout << endl;}
#define prr(v) {for(auto _prr : v) cout << _prr.ff << " " << _prr.ss << endl;}
#define eb emplace_back
using namespace std;
const ll M = 1e9 + 7;
const ll mod = 998244353;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define int long long
const int maxn = 2e5 + 5;
const ll INF = 1e18;
template<class T>
class SegmentTree{
public:
  T t[4*maxn], up[4*maxn];
  void prop(int cur,int L,int R){
    if(up[cur]==0) return;
    t[cur] += up[cur];
    if(L!=R){
      up[2*cur] += up[cur];
      up[2*cur+1] += up[cur];
    }
    up[cur] = 0;
  }
  void update(int l, int r, T x, int cur=1, int L=0, int R = maxn-1){
    prop(cur, L, R);
    if(R < l or L > r) return;
    if(L>=l && R<=r){
      up[cur] += x;
      prop(cur, L, R);
      return;
    }
    int mid = L + R >> 1;
    update(l,r,x, cur*2, L, mid);
    update(l,r,x,cur*2+1, mid+1, R);
    t[cur] = max(t[cur*2], t[cur*2+1]);
  }
  T query(int l, int r, int cur = 1, int L = 0, int R = maxn-1){
    prop(cur, L, R);
    if(R < l or L > r) return INF;
      if(L>=l && R<=r){
        return t[cur];
    }
    int mid = L + R >> 1;
    return max(query(l,r,cur*2, L, mid),query(l,r,cur*2+1, mid+1, R));
  }
};
ll n, m;
vector<pii> qry1[maxn], qry2[maxn];
SegmentTree<ll> tree;
void solve(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		qry1[a].pb({a-1, c});
		qry2[b].pb({a-1, -c});
	}
	tree.update(1, maxn-1, -INF);
	for(int i=1;i<=n;i++){
		for(pii &q : qry1[i]){
			//cout << "OPEN " << q.ff << " " << q.ss << endl;
			tree.update(0, q.ff, q.ss);
		}
		//cout << i << " " << tree.t[1] << endl;
		tree.update(i, i, tree.t[1] + INF);
		for(pii &q : qry2[i]){
			//cout << "CLOSE " << q.ff << " " << q.ss << endl;
			tree.update(0, q.ff, q.ss);
		}
	}
	cout << tree.t[1] << endl;
}
int32_t main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  //cin >> t;
  while(t--){
    solve();
  }
}