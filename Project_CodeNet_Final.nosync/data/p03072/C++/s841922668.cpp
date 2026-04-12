#include <bits/stdc++.h>

#define ll long long
#define mk make_pair
#define pb push_back
#define ff first
#define sc second
#define all(x) x.begin(), x.end();

ll gcd(ll a, ll b){
   if(b == 0) return a;
   
   return gcd(b, a % b);
}

ll sum(int n){
   if(n == 0){
      return n;
   }else{
      return sum(n/10) + n%10;
   }
}
using namespace std;


int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int N; cin >> N;
   vector<int> mountains;
   while(N--){
      int m; cin >> m;
      mountains.pb(m);
   }
   
   int can_see = 1;
   int maxM = mountains[0];
   for(int i = 1; i < mountains.size(); i++){
      if(mountains[i] > maxM) maxM = mountains[i];
      if(mountains[i-1] <= mountains[i] && mountains[i] >= maxM){
         can_see++;
      }
   }

   cout << can_see;
   return 0;
}
