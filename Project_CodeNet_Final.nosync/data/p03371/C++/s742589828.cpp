#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  
  int ans=1e9+7;
  for(int i=0;i<=2*max(x,y);i+=2){
    int sum=i*c+max(x-i/2,0)*a+max(y-i/2,0)*b;
    ans=min(ans,sum);
  }
  
  cout<<ans<<endl;
  
  return 0;
}