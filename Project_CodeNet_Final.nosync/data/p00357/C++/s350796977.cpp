#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;


int main() {
  int n,u=0;
  cin >> n;
  bool t=true;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n){
    if (i*10>u) t=false;
    u=max(u,i*10+a[i]);
  }
  u=0;
  reverse(all(a));
  rep(i,n){
    if (i*10>u) t=false;
    u=max(u,i*10+a[i]);
  }
  if (t) cout << "yes" << endl;
  else cout << "no" << endl;
}

