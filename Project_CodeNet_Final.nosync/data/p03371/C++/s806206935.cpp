#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;
 
long long A, B, C, X, Y;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> A >> B >> C >> X >> Y;
  long long a = A*X + B*Y;
  long long b = C*2*min(X, Y);
  if(X > Y){
     X -= Y;
     b += min(X*A, X*C*2);
  }
  else{
    Y -= X;
    b += min(Y*B, Y*C*2);
  }
  cout << min(a, b) << "\n";
  return 0;
}

