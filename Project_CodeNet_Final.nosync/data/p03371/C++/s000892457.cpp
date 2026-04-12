#include<bits/stdc++.h> 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vv = vector<vector<int>>;
using P = pair<int,int>;

int main(){
  int a,b,c,x,y;
  int ans=0;
  cin >> a >> b >> c >> x >> y;
  x *= 2;
  y *= 2;
  if( c <= (a+b)/2 ){
    while( ( x > 0 && y > 0 ) || 
           ( x > 0 && y <= 0 && a >= 2*c ) ||
           ( x <= 0 && y > 0 && b >= 2*c )   ){
      ans += c;
      x--;
      y--;
    }
  }else{
    while( x > 0 && y > 0 ){
      ans += a+b;
      x -= 2;
      y -= 2;
    }
  }
  while( x <= 0 && y > 0 ){
      ans += b;
      y -=2;
    }
  while( x > 0 && y <= 0 ){
    ans += a;
    x -= 2;
  }
  
  cout << ans << endl;
    
  return 0;
}
