#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  long long kotae=a*x+b*y;
  for(int i=0;i<=max(x,y);i++){
    long long atai=a*max(0,x-i)+b*max(0,y-i)+c*max(2*i,0);
    if(kotae>atai)kotae=atai;
  }
  cout<<kotae<<endl;
  return 0;
}
