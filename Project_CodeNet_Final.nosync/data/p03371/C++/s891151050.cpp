#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(signed i=0;i<n;++i)
#define int long long
#define str string
#define debg(a) cout<<#a<<":"<<a<<endl;
#define vint vector<signed>
#define all(a) a.begin(),a.end()
#define pb(a) push_back((a))
#define yn(a) cout<<((a)?"Yes":"No")<<endl;
#define YN(a) cout<<((a)?"YES":"NO")<<endl;

signed main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  vint ans;
  if(a+b>2*c){
    if(x==y)ans.pb(2*c*x);
    else if(x>y)ans.pb(2*c*y+a*(x-y));
    else ans.pb(2*c*x+b*(y-x));
  }
  ans.pb(a*x+b*y);
  ans.pb(2*c*max(x,y));
  sort(all(ans));
  cout<<ans[0];
  
  return 0;
}
