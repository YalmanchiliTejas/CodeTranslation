#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int inf=1000000007;
signed main(){
  int a,b,c;cin>>a>>b>>c;
  int res=inf;
  int x,y;cin>>x>>y;
  res=a*x+b*y;
  if(x>y){
    int buf=c*2*y+a*(x-y);
    res=min(buf,res);
  }
  else{
    int buf=c*2*x+b*(y-x);
    res=min(res,buf);
  }
  res=min(res,c*2*max(x,y));
  cout<<res<<endl;
  return 0;
}