#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rng(i,a,b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define repd(i, n) for(ll i = (ll)(n)-1;i>=0;--i)
#define rngd(i,b,a) for(ll i = (ll)(b);i>=a;--i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((ll)(x).size())
#define ctoi(x) ((x)-'0')

int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<bool> > e(n,vector<bool>(n));
  vector<int> x(n);
  rep(i,n){
    x[i]=i;
  }
  rep(i,m){
    int a,b;
    cin>>a>>b;
    e[a-1][b-1]=1;
    e[b-1][a-1]=1;
  }
  int ans=0;
  int cnt=0;
  do{
    cnt=0;
    rep(i,n){
     if(i>=n-1){
        break;
      }
      if(e[x[i]][x[i+1]]){
        cnt++;
      }else{
        break;
      }
    }
    if(cnt==n-1){
      ans++;
    }
  }while(next_permutation(x.begin()+1,x.end()));
  cout<<ans<<endl;
  return 0;
}