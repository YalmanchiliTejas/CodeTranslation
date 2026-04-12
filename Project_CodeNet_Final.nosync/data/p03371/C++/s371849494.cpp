#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,k,cnt;
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  if(a+b<2*c){
    cout<<a*x+b*y;
    return 0;
  }
  if(x<=y){
    cout<<2*c*x+min(b,2*c)*(y-x);
  }else{
    cout<<2*c*y+min(a,2*c)*(x-y);
  }
}