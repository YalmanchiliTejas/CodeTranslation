#include <bits/stdc++.h> 

#define INF INT_MAX/2;
#define MOD 1000000007

using namespace std;

using ll = long long;
using ull = unsigned long long ;

int main(){
   std::ios::sync_with_stdio(false);
   std::cin.tie(0);

   ll N,K;
   cin>>N>>K;
   ll ans = 0;
   if(K==0){
      cout<<N*N<<endl;
      return 0;
   }
   for(ll i=K+1;i<=N;i++){
      ans += (N/i)*(i-K);
      ans += max((ll)0,(N%i)-K+1);
   }
   cout<<ans<<endl;
   return 0; 
}
