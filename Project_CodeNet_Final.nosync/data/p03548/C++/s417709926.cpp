#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}
using namespace std;
int main(){ 
   int x,y,z;
   cin>>x>>y>>z;

   int sum=y+2*z;
   for(int i=1;i<100000;i++){
      if((sum+y+z)>x){
         cout<<i;
         break;
      }
      else sum+=y+z;
   }
   



   
   return 0;
}