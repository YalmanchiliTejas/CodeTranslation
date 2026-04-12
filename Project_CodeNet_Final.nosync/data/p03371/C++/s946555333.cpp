#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int a,b,c,x,y,cnt=0,tmp;
  cin >> a >> b >> c >> x >> y;
  c*=2;
  if(a+b>c){
    cnt+=min(x,y)*c;
    tmp=min(x,y);
    x-=tmp;
    y-=tmp;
    if(x){
      cnt+=min(a,c)*x;
    }
    else cnt+=min(b,c)*y;
  }
  else{
    cnt+=a*x+b*y;
  }
  cout << cnt << endl;
}