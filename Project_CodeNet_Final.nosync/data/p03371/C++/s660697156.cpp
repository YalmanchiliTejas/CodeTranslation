#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
   ll A,B,C,X,Y;
   cin>>A>>B>>C>>X>>Y;
   ll ans=0;
   if(C*2<A+B){
       if(Y<X){
           ans+=C*2*Y;
           ans+=min(A,C*2)*(X-Y);
       }
       else{
           ans+=C*2*X;
           ans+=min(C*2,B)*(Y-X);
       }
   }
   else{
       ans=A*X+B*Y;
   }
   cout<<ans<<endl;
}
