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

int main(){
  int n;
  cin >> n;
  vector<int> a(n,0);
  rep(i,n){ cin >> a[i]; }

  deque<int> d;
  rep(i,n){
    int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    if(p==0){
      d.push_front(a[i]);
    } else {
      d[p-1] = a[i];
    }
  }
  int ans=d.size();
  cout << ans << endl;
  return 0;  
}