#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;


int main() {
  int n;
  cin >> n;
  vi v(n);
  rep(i,n){
    cin >> v[i];
  }
  int hmax=v[0];
  int ans=0;
  rep(i,n){
    if(v[i]>=hmax){
      ans++;
      hmax=v[i];
    }
  }
  cout << ans << endl;
  return 0;
  
}