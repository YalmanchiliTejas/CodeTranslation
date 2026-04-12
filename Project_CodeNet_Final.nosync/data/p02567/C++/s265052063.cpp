#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;

#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define uniq(x) ((x).erase(unique(all(x)),(x).end()))
#define sz(x) ((int)(x).size())

#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)

#ifdef LOCAL//compile with -DLOCAL
#define debug(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl
#define debug_vec(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = ";\
  rep(i,sz(x)){cerr<<x[i]<<" ";}cerr<<endl
#define debug_mat(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<endl;\
  rep(i,sz(x)){rep(j,sz(x[i])){cerr<<x[i][j]<<" ";}cerr<<endl;}cerr<<endl
#else
#define debug(x) void(0)
#define debug_vec(x) void(0)
#define debug_mat(x) void(0)
#endif

template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}


int op(int a, int b){
  return max(a, b);
}

int e(){
  return -1;
}

int target;
bool f(int v){
  return v < target;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N,Q;
  cin >> N >> Q;
  vector<int> A(N);
  rep(i,N)  cin >> A.at(i);

  segtree<int, op, e> seg(A);
  rep(_,Q){
    int t;
    cin >> t;
    if(t == 1){
      int x,v;
      cin >> x >> v;
      x--;
      seg.set(x, v);
    }
    else if(t == 2){
      int l,r;
      cin >> l >> r;
      l--;
      r--;
      cout << seg.prod(l, r+1) << endl;
    }
    else if(t == 3){
      int x,v;
      cin >> x >> v;
      x--;
      target = v;
      cout << seg.max_right<f>(x) + 1 << endl;
    }
  }

  return 0;
}