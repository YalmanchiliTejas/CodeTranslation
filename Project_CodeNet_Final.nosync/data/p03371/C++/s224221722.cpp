#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int a,b,c,x,y;
signed main(){
  cin>>a>>b>>c>>x>>y;
  int res=0;
  res+=min(x,y)*(min(a+b,2*c));
  if(x<y){
    res+=min(b,2*c)*(y-x);
  }
  else{
    res+=min(a,2*c)*(x-y);
  }
  cout<<res<<endl;
  return 0;
}
