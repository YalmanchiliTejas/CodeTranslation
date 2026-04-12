#include<bits/stdc++.h>
using namespace std;
 int main(){
  int a,b,c,x,y;
   cin>>a>>b>>c>>x>>y;
   c*=2;
   if(x>y){swap(x,y);swap(a,b);}
   if(a+b<c)cout<<x*a+y*b<<endl;
   else{
    if(b<c)cout<<x*c+b*(y-x)<<endl;
    else cout<<c*y<<endl;
     }
      
  return 0;
 }