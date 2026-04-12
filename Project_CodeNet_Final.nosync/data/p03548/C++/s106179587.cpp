#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define rrep(i,n) for(int i=1; i<=(n); ++i)
#define drep(i,n) for(int i=(n)-1; i>=0; --i)
#define srep(i,s,t) for (int i=s; i<t; ++i)
#define pb push_back
using namespace std;
using P = pair<int,int>;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef tuple<int,int,int> T;
typedef vector<P> vp;
typedef vector<T> vt;

// head
int main(){
  int x,y,z;
  cin >> x >> y >> z;
  int ans=0;
  ans=max(ans,(x-z)/(y+z));
  cout << ans << endl;
  return 0;
}