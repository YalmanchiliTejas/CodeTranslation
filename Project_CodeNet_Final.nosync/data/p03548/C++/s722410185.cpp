#include <bits/stdc++.h> 

#define INF INT_MAX/2;
#define MOD 1000000007

using namespace std;

using ll = long long;
using ull = unsigned long long ;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);

   int X,Y,Z;
   cin>>X>>Y>>Z;

   int ans = 0;
   while(X>=Z+Y+Z){
      X -= Z+Y;
      ans++;
   }
   cout<<ans<<endl;
   return 0; 
}
