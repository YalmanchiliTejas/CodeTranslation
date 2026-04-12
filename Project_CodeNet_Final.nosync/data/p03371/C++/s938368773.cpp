#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int a , b , c , x , y ;
  cin >> a >> b >> c >> x >> y ;
  intll ans = INF ;
  
 for(int i=0 ; i <300000;i+=2){
   intll now = 0;
   now += c*i ;
   now += max(0, x-(i/2)) * a ;
   now += max(0, y-(i/2)) * b ;
   
   ans = min(ans,now);
 }
  
  cout <<ans ; 

    
  
}
