#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define All(a) (a).begin(),(a).end()

int main(){ 
  int a,b,c,x,y;
  ll ans=0;
  cin >> a>> b>>c>>x>>y;
  if(a+b<2*c){
    cout<<a*x+b*y<<endl;
    return 0;
  }else{
    int tmp=min(x,y);
    x-=tmp;y-=tmp;
    ans+=c*tmp*2;

    if(x>0 && a>2*c){
      ans+=x*c*2;
      x=0;
    }else if(y>0 && b>2*c){
      ans+=y*c*2;
      y=0;
    }else{
      ans+=a*x+b*y;
    }
    
    cout << ans <<endl;
  }

  return 0;
}