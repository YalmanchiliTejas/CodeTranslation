#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int ab = min(x,y);
  ll sum = 0;
  if(a+b>2*c){
      sum += 2*ab*c;
  }else{
      sum += a*ab+b*ab;
  }
  if(a<2*c){
    if(x-ab>0){
        sum += a*(x-ab);
    }
  }else{
     if(x-ab>0){
        sum += 2*c*(x-ab);
    } 
  }
  if(b<2*c){
    if(y-ab>0){
        sum += b*(y-ab);
    }
  }else{
      if(y-ab>0){
        sum += 2*c*(y-ab);
    }
  }
  
  cout<<sum<<endl;
}