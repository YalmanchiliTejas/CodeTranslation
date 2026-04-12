#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__",", __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000

int main(){
  int n;
  cin>>n;
  vector<long> x(n),y(n);
  rep(i,n) cin>>x[i]>>y[i];
  rep(i,n) if(x[i]>y[i]) swap(x[i],y[i]);

  // x[i] < y[i]

  vector<pair<long,int>> ps(2*n);
  rep(i,n) ps[i*2]=mp(x[i],i), ps[i*2+1]=mp(y[i],i);
  sort(all(ps));

  int j = ps[0].se;
  int k = ps[2*n-1].se;

  if(j == k){
    long mx = 0;
    long mn = INF;
    rep(i,n) if(i!=k){
      mx = max(mx, x[i]);
      mn = min(mx, y[i]);
    }
    long xx = y[k];
    long nn = x[k];
    long ans = (xx-mn)*(mx-nn);
    cout << ans << endl;
    return 0;
  }

  // j: smallest, k: largest

  long ans = 1234567890123456789LL;
  {
    // min,maxちがう色 -> 各ペアの大小だけで
    long mx = x[k];
    long mn = y[j];
    rep(i,n) if(i!=k && i!=j){
      mx = max(mx, x[i]);
      mn = min(mn, y[i]);
    }
    ans = min(ans, (y[k]-mn)*(mx-x[j])); //dbg(ans);
  }
  {
    // min,maxおなじ色
    multiset<int> st;
    st.insert(x[k]);
    st.insert(y[j]);

    rep(i,n)if(i!=k && i!=j) st.insert(x[i]);

    int w = *(--st.end()) - *(st.begin());
    repl(i,1,2*n-1){
      int idx = ps[i].se;
      if(idx==k || idx==j) continue;
      if(ps[i].fi == y[idx]) continue;
      st.erase(st.lower_bound(x[idx]));
      st.insert(y[idx]);
      int nw = *(--st.end()) - *(st.begin()); //dbg(i,nw);
      w = min(w, nw);
    }

    long aa = (y[k]-x[j])*w;

    ans = min(ans, aa);
  }

  cout << ans << endl;

  return 0;
}
