#include<bits/stdc++.h>
using namespace std;
int i,j,n,l,a,b,c;
int main(){
  cin>>a>>b>>c>>i>>j;
  if(a+b>2*c){
    l=2*c*max(i,j);
    if(i>j)cout<< min(l,a*(i-j)+2*c*j);
    else cout<< min(l,b*(j-i)+2*c*i);
  }
  else cout<<i*a+j*b;
}