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
   int h,w;
   cin>>h>>w;
   char a[h][w];
   rep(i,h){
      rep(j,w){
         cin>>a[i][j];
      }
   }

   vector<bool> gyou(h,false);
   vector<bool> retsu(w,false);

   rep(i,h){
      bool f=false;
      rep(j,w){
         if(a[i][j]=='#') f=true;
      }
      if(f==true) gyou[i]=true;
   }
   rep(i,w){
      bool f=false;
      rep(j,h){
         if(a[j][i]=='#') f=true;
      }
      if(f==true) retsu[i]=true;
   }

   rep(i,h){
      rep(j,w){
         if(gyou[i]==true && retsu[j]==true){
             cout<<a[i][j];
         }
      }
      if(gyou[i]!=false) cout<<endl;
   }
   

   return 0;
}

