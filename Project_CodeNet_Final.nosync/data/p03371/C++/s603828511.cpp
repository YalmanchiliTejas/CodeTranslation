#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   ll a,b,c,x,y;
   cin >>a>>b>>c>>x>>y;
   ll ans=0;
   if(a+b>=2*c){
       ans+=2*c*min(x,y);

   }
   else {
       ans+=a*min(x,y);
       ans+=b*min(x,y);
   }
    if(x>=y){
        x-=y;
        y=0;
    }
    else {
        y-=x;
        x=0;
    }
   ans+=min(2*c,a)*x;
   ans+=min(2*c,b)*y;
   cout <<ans <<endl;
   return 0;
}