#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

int main() {
  int n;
  cin >> n;
  deque<int> c;
  rep(i,n){
    int a; cin >> a;
    int pos = lower_bound(c.begin(),c.end(),a) - c.begin();
    if(pos==0){
      c.push_front(a);
    } else {
      c[pos-1] = a;
    }
  }

  int ans = c.size();
  cout << ans << endl;
  return 0;
}