#include <bits/stdc++.h>
using namespace std;

int main(){
   int a,b,c,x,y;
   cin >>a >>b >>c >>x >>y;
   int ans=0;
   int min;
   if(c*2<=a+b){
   if(x>=y){
         ans+=c*y*2;
         if(c*2>a)ans+=(x-y)*a;
         else ans+=(x-y)*c*2;
   }
   else{
         ans+=c*x*2;
         if(2*c>b)ans+=(y-x)*b;
         else ans+=(y-x)*2*c;
   }
   }
   if(c*2>a+b){
      ans+=a*x+b*y;
   }
   cout <<ans <<endl;
}