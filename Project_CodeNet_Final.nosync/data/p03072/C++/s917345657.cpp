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
  int h[n];
  rep(i,n)cin>>h[i];
  int ans = 0;
  rep(i,n){
    bool flag = 1;
    rep(j,i){
      if(h[j]>h[i])flag = 0;
    }
    if(flag)ans++;
  }
  cout << ans << endl;
}