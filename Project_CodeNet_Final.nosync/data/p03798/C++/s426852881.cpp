#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef pair<double,double> PD;
typedef pair<int,P> ed;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;

void calc(vi &a,int N,string &s) {
  srep(i,2,N) {
    bool same = a[i-1]^(s[i-1]=='o');
    if(same) {
      a[i] = a[i-2];
    } else {
      a[i] = 1-a[i-2];
    }
  }
}

bool valid(vi &a,int N,string &s) {
  bool same = a[0]^(s[0]=='o');
  if(same) {
    if(a.back() != a[1]) return false;
  } else {
    if(a.back() == a[1]) return false;
  }
  same = a.back()^(s.back()=='o');
  if(same) {
    if(a[N-2] != a[0]) return false;
  } else {
    if(a[N-2] == a[0]) return false;
  }
  return true;
}

void out(vi &a,int N) {
  rep(i,N) {
    cout << (a[i]?'W':'S');
  }
  cout << endl;
}
  
int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  rep(i,1<<2) {
    vi a(N);
    a[0] = i&1;
    a[1] = (i>>1)&1;
    calc(a,N,s);
    if(valid(a,N,s)) {
      out(a,N);
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}