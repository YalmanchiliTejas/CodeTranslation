#include <bits/stdc++.h> 

#define INF INT_MAX/2
#define MOD 1000000007

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);

   int A,B,C,X,Y;
   cin>>A>>B>>C>>X>>Y;
   ll MIN = 1<<30;
   for(int i=0;i<=max(X,Y);i++){
      ll money = 0;
      money += 2*i*C;
      money += max((X-i),0)*A+max((Y-i),0)*B;
      MIN = min(money,MIN);
   }
   cout<<MIN<<endl;
   return 0; 
}
