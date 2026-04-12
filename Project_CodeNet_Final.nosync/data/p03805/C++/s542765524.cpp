#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(x)    (x).begin(),(x).end()
typedef long long ll;
const int MOD = (int)1e9 + 7;

int solve(vector<int> a, vector<int> b, vector<int> parm, vector<int> use,int n,int m){
  if(n == parm.size()){
    //rep(i,n) cout<<parm[i];
    //cout<<endl;
    bool ans = true;
    rep(i,n-1){
      bool buf = false;
      rep(j,m)
        if ((parm[i]==a[j]-1&&parm[i+1]==b[j]-1)||(parm[i]==b[j]-1&&parm[i+1]==a[j]-1))
          buf = true;
      ans = ans && buf;
    }
    //cout<<ans<<endl;
    return ans ? 1 : 0 ;
  }
  int ans = 0;
  rep(i,n){
    if(use[i] == 0){
      use[i] = 1;
      parm.push_back(i);
      ans += solve(a,b,parm,use,n,m);
      use[i] = 0;
      parm.pop_back();
    }
  }
  return ans;
}
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m),b(m);
  vector<int> parm,use(n,0);
  rep(i,m) cin >> a[i] >> b[i];
  use[0] = 1;
  parm.push_back(0);
  cout << solve(a,b,parm,use,n,m) << endl;
}

