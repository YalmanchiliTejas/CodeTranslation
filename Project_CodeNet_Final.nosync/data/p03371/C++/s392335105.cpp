#include <iostream>

using namespace std;

int main()
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans {0};
  
  int n {min(X,Y)};
  if(C*2 <= A + B){
    ans += C*2*n;
  }else{
    cout << X*A+Y*B << endl;
    return 0;
  }

  X -= n;
  Y -= n;

  if(X == 0){
    if(C*2 <= B){
      cout << ans+C*2*Y << endl;
    }else{
      cout << ans+Y*B << endl;
    }
  }else{
    if(C*2 <= A){
      cout << ans+C*2*X << endl;
    }else{
      cout << ans+X*A << endl;
    }
  }
}
