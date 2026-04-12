#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<LL> v(n);
  rep(i,n) cin >> v[i];
  LL ans=0;
  repp(i,1,n){
    int kab=0;
    LL s=0,t=0;
    for(;kab<n-1;kab+=i){
      int a = n-1-kab;
      if(a<=i) break;
      if(a%i==0&&a<=kab) break;
      t+=v[a];
      s+=v[kab];
      ans=max(ans,s+t);
    }
  }
  cout << ans << endl;
  return 0;
}
