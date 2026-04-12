#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define EPS (1e-9)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

const string YES = "";
const string NO  = "";

typedef long long ll;

void solve() {

}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> v;
  for(int i=n-1;i>=0;--i) {
    if( v.empty() ) v.pb(a[i]);
    else {
      int ptr = upper_bound(ALL(v),a[i]) - v.begin();
      if( ptr < (int)v.size() ) v[ptr] = a[i];
      else v.pb(a[i]);
    }
  }
  cout << v.size() << endl;
  return 0;
}
