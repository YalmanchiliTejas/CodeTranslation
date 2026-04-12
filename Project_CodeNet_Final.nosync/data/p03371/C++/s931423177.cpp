#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;


int main(){
   int a,b,c,x,y;
   cin>>a>>b>>c>>x>>y;
   int ans=0;
   if(a+b<=2*c){
      ans=a*x+b*y;
   }
   else{
      if(x>=y){
         if(a<=c*2){
            ans=c*2*y+a*(x-y);
         }
         else{
            ans=c*2*x;
         }
      }
      else{
         if(b<=c*2){
            ans=c*2*x+b*(y-x);
         }
         else{
            ans=c*2*y;
         }
      }
   }
   cout<<ans<<endl;
}