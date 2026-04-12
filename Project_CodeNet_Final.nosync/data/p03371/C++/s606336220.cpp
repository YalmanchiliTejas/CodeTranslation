#include <bits/stdc++.h>
#define INF 100100100
#define MOD 1000000007

using namespace std;
using ll = long long;
using ull = unsigned long long ;

#define FOR(i,n) for(ll i=0;i<n;i++)

struct edge{ll to,cost;};

int main(int argc, char const* argv[]){
   ios::sync_with_stdio(false);
   cin.tie(0); 
   ull A,B,C,X,Y;
   cin >> A >> B >> C >> X >> Y;
   if(X<Y)swap(A,B),swap(X,Y);
   if(C*2 < A + B){
      if(Y*C*2 + (X-Y)*A < X*C*2){
         cout << Y*C*2 + (X-Y)*A << endl;  
      }
      else{
         cout << X*C*2 << endl;
      }
   }
   else cout << A*X + B*Y << endl;
   return 0;
}
