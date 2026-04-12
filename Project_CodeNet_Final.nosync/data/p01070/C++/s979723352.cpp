#include <bits/stdc++.h>
using namespace std;
#define _MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) _MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define mp make_pair
#define pb push_back
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cerr<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cerr<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

class SuffixArray {
public:
  string &s;
  vector<int> sa, rank;
  int n;
  void construct_sa(){
    sa.resize(n+1);
    rank.resize(n+1);
    rep(i,n+1){
      sa[i]=i;
      rank[i] = (i<n)?s[i]:(-1);
    }
    vector<int> tmp(n+1,0);
    for(int k=1; k<=n; k*=2){
      auto comp = [&](const int i, const int j){
        if(rank[i]!=rank[j]) return rank[i]<rank[j];
        int ri = (i+k<=n)?(rank[i+k]):-1;
        int rj = (j+k<=n)?(rank[j+k]):-1;
        return ri < rj;
      };
      sort(all(sa), comp);
      tmp[sa[0]]=0;
      rep(i,1,n+1){
        tmp[sa[i]] = tmp[sa[i-1]];
        if(comp(sa[i-1], sa[i])) tmp[sa[i]]++;
      }
      swap(tmp, rank);
    }
  }
  SuffixArray(string &str) : s(str){
    n = s.size();
    construct_sa();
  }
  int getRank(const string t){
    int m = t.size();
    int l = 0, r = n+1;
    while(r-l>1){
      int mid = (r+l)/2;
      if(s.compare(sa[mid], m, t) < 0) l = mid;
      else r = mid;
    }
    return r;
  }
};

int rank_v[100005];

class SegTree{
public:
  int n;
  vector<int> data[1<<18];
  SegTree(int n_){
    n=1;
    while(n<n_) n*=2;
    rep(i,n_){
      data[n-1+i].pb(rank_v[i]);
    }
    for(int i=n-2; i>=0; i--){
      int il = 2*i+1, ir = 2*i+2;
      data[i].resize(data[il].size()+data[ir].size());
      merge(all(data[il]), all(data[ir]), data[i].begin());
    }
  }
  // 区間[a,b)でx以下の個数
  int query(int a, int b, int x, int k, int l, int r){
    if(r<=a || b<=l) return 0;
    if(a<=l && r<=b){
      return upper_bound(all(data[k]), x) - data[k].begin();
    }
    int vl = query(a,b,x,k*2+1,l,(r+l)/2);
    int vr = query(a,b,x,k*2+2,(r+l)/2,r);
    return vl+vr;
  }
  int query(int a, int b, int x){
    return query(a,b,x,0,0,n);
  }
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s;
  int q;
  cin>>s>>q;
  SuffixArray sa(s);
  int n = s.size();

  rep(i,n) rank_v[i] = sa.rank[i];
  SegTree st(s.size());
// dbg(sa.rank, sa.sa);
  rep(_,q){
    int l,r;
    string t;
    cin>>l>>r>>t;
    r = r+1 - (t.size()-1);
    int lb = sa.getRank(t);
    int ub = sa.getRank(t+'|');
    // dbg(lb,ub);

    int ans = st.query(l,r,ub-1) - st.query(l,r,lb-1);
    cout << ans << endl;
  }

  return 0;
}

