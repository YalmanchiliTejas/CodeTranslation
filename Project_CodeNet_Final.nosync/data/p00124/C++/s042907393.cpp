#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rrep(i,n) for(int i=(int)(n)-1; i>=0; i--)
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin(); it!=(c).end(); it++)
#define pb(a) push_back(a)
#define pr(a) cout << (a) << endl
#define PR(a,b) cout << (a) << " " << (b) << endl
#define F first
#define S second
typedef long long ll;
typedef pair<int,string> P;
const int MAX=1000000001;
const ll MAXL=1000000000000000001LL;
const ll mod=1000000007;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

bool cmp(P a, P b) {
  return a.first>b.first;
}

vector<P> m(vector<P> a) {
  if(a.size()==1) return a;
  if(a.size()==2) {
    inplace_merge(a.begin(),a.begin()+1,a.end(),cmp);
    return a;
  }
  vector<P> b,c;
  for(int i=0; i<a.size(); i++) {
    if(i<a.size()/2) b.push_back(a[i]);
    else c.push_back(a[i]);
  }
  b=m(b);
  c=m(c);
  copy(c.begin(), c.end(), back_inserter(b)); 
  inplace_merge(b.begin(),b.begin()+(b.size()-c.size()),b.end(),cmp);
  return b;
}

int main() {
  int n;
  bool ck=false;
  while(cin >> n && n) {
    if(ck) cout << endl;
    ck=true;
    vector<P> a(n);
    rep(i,n) {
      string s;
      int x,y,z;
      cin >> s >> x >> y >> z;
      a[i].F=x*3+z;
      a[i].S=s;
    }
    a=m(a);
    rep(i,n) cout << a[i].S << "," << a[i].F << endl;
  }
  return 0;
}
