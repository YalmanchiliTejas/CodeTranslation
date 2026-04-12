#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
  //2c a+b
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ll ans=1000000000000;
  
    int mx=max(x,y);
    
      ll count=0;
      int mn=min(x,y);
      
    for(int i=0;i<=2*mx;i+=2){ //iはcの枚数/
      count=0;
      count+=i*c;
      if(x-i/2>0)
      count+=(x-i/2)*a;
      if(y-i/2>0)
      count+=(y-i/2)*b;
    
    
    
    
    ans=min(ans,count);
  }
  cout<<ans<<endl;
}