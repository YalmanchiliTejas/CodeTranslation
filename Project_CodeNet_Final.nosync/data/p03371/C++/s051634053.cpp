#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  
  int ans=a*x+b*y;
  int harf=max(x,y)*c*2;
  if(harf<ans)ans=harf;
  int plus=max(x,y)-min(x,y);
  int mix=min(x,y)*c*2;
  if(max(x,y)==x){
    mix+=a*plus;
    if(mix<ans)ans=mix;
  }else{
    mix+=b*plus;
    if(mix<ans)ans=mix;
  }

  cout << ans << endl;
}