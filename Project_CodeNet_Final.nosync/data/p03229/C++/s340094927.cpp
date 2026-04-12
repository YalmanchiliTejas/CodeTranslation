#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
   int N;
   cin>>N;
   vector<int>A(N);
   rep(i,N){
       cin>>A[i];
   }
   sort(A.begin(),A.end());
   ll ans=0;
   if(N%2==0){
       rep(i,N){
           if(i<N/2){
               ans-=A[i]*2;
           }
           else{
               ans+=A[i]*2;
           }
       }
       ans+=A[N/2-1];
       ans-=A[N/2];
   }
   else{
   ll Q=0;
    rep(i,N){
      if(i<N/2){
        Q-=A[i]*2;
      }
      else{
        Q+=A[i]*2;
      }
    }
     Q-=A[N/2];
     Q-=A[N/2+1];
   rep(i,N){
       if(i<=N/2){
           ans-=A[i]*2;
       }
       else{
           ans+=A[i]*2;
       }
   }
   ans+=A[N/2-1];
   ans+=A[N/2];
     ans=max(ans,Q);
   }
   cout<<ans<<endl;
}
