#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI acos(-1)
typedef  long long ll;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}

int main(){
   int a,b,c,x,y;
   cin>>a>>b>>c>>x>>y;

   int d=min(a+b,2*c);
   if(d==2*c){
      if(x>=y){
         cout<<2*c*y+min((x-y)*a,(x-y)*2*c);
      }
      else{
         cout<<2*c*x+min((y-x)*b,(y-x)*2*c);
      }
   }
   else{
      cout<<a*x+b*y;
   }


   return 0;
}
