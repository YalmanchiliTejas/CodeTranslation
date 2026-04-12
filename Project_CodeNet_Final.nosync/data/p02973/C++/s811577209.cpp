#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  rep(i,n)cin >> a[i];
  deque<int> d;
  rep(i,n){
    auto id = lower_bound(d.begin(),d.end(),a[i]) - d.begin();
    if(id==0)d.push_front(a[i]);
    else d[id-1]=a[i];
  }
  cout << d.size() << endl;
}