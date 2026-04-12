#include <bits/stdc++.h>
#define INF 2e9
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

// int ctoi(const char c){
//   if('0' <= c && c <= '9') return (c-'0');
//   return -1;
// }

// int gcd(int a, int b){
//   int ma = max(a,b);
//   int mi = min(a,b);
//   if(mi == 0) return ma;

//   return gcd(mi, ma%mi);
// }
int main(){
  llong A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  if(2 * C >= A + B){
    cout << A * X + B * Y << endl;
    return 0;
  }else if(2 * C > A && 2 * C > B){
    if(X > Y){
      cout << 2 * C * Y + A * (X-Y) << endl;
      return 0;
    }else{
      cout << 2 * C * X + B * (Y-X) << endl;
      return 0;
    }
  }else if(2 * C < min(A,B)){
    cout << 2 * C * max(X,Y) << endl;
    return 0;
  }else{
    if(X>Y && A>B){
      cout << 2 * C * X << endl;
      return 0;
    }else if(X<=Y && A<=Y){
      cout << 2 * C * Y << endl;
      return 0;
    }else if(X > Y){
      cout << 2 * C * Y + A * (X-Y) << endl;
      return 0;
    }else{
      cout << 2 * C * X + B * (Y-X) << endl;
      return 0;
    }
  }
}
