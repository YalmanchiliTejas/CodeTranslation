#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
using ll = long long;
using P = pair<ll,int>;
using G = vector<vector<int>>;
const long long INF = 1LL << 60;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
 if(a+b >= c*2){
   if(y >= x){
     if(b > c*2){
       ans = c*2*y;
     }else{
       ans = (2*c) * x + b * (y-x); 
     }
   }else{
     if(a > c*2){
       ans = c*2*x;
     }else{
       ans = (2*c) * y + a * (x-y); 
     }
   }
 }else{
   ans = a*x + b*y;
 } 
 cout << ans <<  endl;
}