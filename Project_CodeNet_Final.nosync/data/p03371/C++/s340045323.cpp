#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ab_buy = min(x, y) * 2 * c;
  int a_buy = (max(x, y)-min(x, y)) * a;
  int b_buy = (max(x, y)-min(x, y)) * b;
  if(x>=y){
    int mn = min(ab_buy + a_buy, (a*x + b*y));
    int ans = min(mn, c*max(x,y)*2);
    cout  << ans << endl;
    return 0;
  }
  else if(x<=y){
    int mn = min(ab_buy + b_buy, (a*x + b*y));
    int ans = min(mn, c*max(x,y)*2);
    cout  << ans << endl;
 }


}