#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;
const int INF = 1e9;

int NN = 1;
struct Node{
  int mn, mx;
  int lazy;
};
Node segT[2*(1<<20)-1];

class LazySegT{
public:
  LazySegT(){
	for(int i=0;i<2*NN-1;++i){
	  segT[i].mn = INF;
	  segT[i].mx = -INF;
	  segT[i].lazy = INF;
	}
  }

  void eval(int k, int l, int r){
	// ???????????????????????????
	if(segT[k].lazy == INF) return;
	
	segT[k].mx += segT[k].lazy;
	segT[k].mn += segT[k].lazy;
	if(k < NN-1){ // not leaf
	  if(segT[2*k+1].lazy == INF) segT[2*k+1].lazy = 0;
	  segT[2*k+1].lazy += segT[k].lazy;
	  if(segT[2*k+2].lazy == INF) segT[2*k+2].lazy = 0;
	  segT[2*k+2].lazy += segT[k].lazy;
	}
	segT[k].lazy = INF;
  }
  // dat[idx] := c
  void update1(int idx, int c, int k=0, int l=0, int r=NN){
	if(r <= idx || idx < l) return;
	if(l == idx && r-l == 1){
	  segT[k].mx = segT[k].mn = c;
	}
	else{
	  update1(idx, c, k*2+1, l, (l+r)/2);
	  update1(idx, c, k*2+2, (l+r)/2, r);
	  segT[k].mx = max(segT[k*2+1].mx, segT[k*2+2].mx);
	  segT[k].mn = min(segT[k*2+1].mn, segT[k*2+2].mn);
	}
  }
  
  // dat[a,b) += c
  void update(int a, int b, int c, int k=0, int l=0, int r=NN){
	eval(k,l,r);
	if(r <= a || b <= l) return;

	if(a <= l && r <= b){
	  segT[k].lazy = c;
	  eval(k,l,r);
	}
	else{
	  update(a, b, c, k*2+1, l, (l+r)/2);
	  update(a, b, c, k*2+2, (l+r)/2, r);
	  segT[k].mx = max(segT[k*2+1].mx, segT[k*2+2].mx);
	  segT[k].mn = min(segT[k*2+1].mn, segT[k*2+2].mn);
	}
  }

  // return (max,min) in [a,b)
  PII query(int a, int b, int k=0, int l=0, int r=NN){
	eval(k,l,r);
	// no intersect
	if(r <= a || b <= l) return MP(-INF,INF);

	// completely contain
	if(a <= l && r <= b) return MP(segT[k].mx, segT[k].mn);
	else{
	  auto vl = query(a, b, k*2+1, l, (l+r)/2);
	  auto vr = query(a, b, k*2+2, (l+r)/2, r);
	  segT[k].mx = max(segT[k*2+1].mx, segT[k*2+2].mx);
	  segT[k].mn = min(segT[k*2+1].mn, segT[k*2+2].mn);
	  return MP(max(vl.FF,vr.FF), min(vl.SS,vr.SS));
	}
  }
};


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  int HN = N / 2;
  while(NN < HN) NN <<= 1;
  LazySegT seg;
  VI xs(HN);
  REP(i,HN){
	int x; cin >> x;
	xs[i] += x;
  }
  REP(i,HN){
	int x; cin >> x;
	xs[HN-i-1] -= x;
  }
  REP(i,HN){
	seg.update1(i,xs[i]);
  }
	
  int Q; cin >> Q;
  REP(q,Q){
	int l, r, x; cin >> l >> r >> x; --l;
	if(HN <= l){
	  l = N - l;
	  r = N - r;
	  seg.update(r,l,-x);
	}
	else if(r <= HN)
	  seg.update(l,r,x);
	else{
	  seg.update(l,HN,x);
	  seg.update(N-r,HN,-x);
	}
	auto res = seg.query(0,HN);

	cout << (res.FF == 0 && res.SS == 0) << endl;
  }

  return 0;
}