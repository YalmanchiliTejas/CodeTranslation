#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;
using namespace std;

ll modinv(ll a,ll m){
   ll b=m,u=1,v=0;
   while(b){
      ll t=a/b;
      a-=t*b; 
      swap(a,b);
      u-=t*v; 
      swap(u,v);
   }
   u%=m;
   if(u<0) u+=m;
   return u;
}

ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}



int main(){
   int n;
   cin>>n;
   vector<int> a(n);
   rep(i,n){
      cin>>a[i];
   }
   int count=0;

   rep(i,n){
      bool f=true;
      
      
         for(int j=0;j<i;j++){
            if(a[i]<a[j]) f=false;
         }
      
      if(f) count++;
       
   }
   cout<<count;
   return 0;
}

