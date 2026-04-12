#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y,money=1000000000;
  cin>>a>>b>>c>>x>>y;
  for(int i=0;i<=100000;i++){
    money=min(money,i*2*c+max(0,x-i)*a+max(0,y-i)*b);
  }
  cout<<money<<endl;
}