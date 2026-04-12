#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  long long kotae=a*x+b*y;
  for(int i=1;i<=max(x,y);i++){
    int a_mai=max(x-i,0);
    int b_mai=max(y-i,0);
    long long tmp=a*a_mai+b*b_mai+c*2*i;
    if(kotae>tmp)kotae=tmp;
    else break;
  }
  cout<<kotae<<endl;
  return 0;
}