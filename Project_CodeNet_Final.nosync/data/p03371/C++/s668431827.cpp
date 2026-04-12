#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
     ifstream in("input.txt");
     cin.rdbuf(in.rdbuf());
  //*/
  long double A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = 0;
  if((A + B) / 2 >= C){
    int d = min(X, Y);
    ans += C * d * 2;
    X -= d;
    Y -= d;
  }
  if(A >= C * 2){
    ans += C * 2 * X;
  } else{
    ans += A * X;
  }
  if(B >= C * 2){
    ans += C * 2 * Y;
  } else{
    ans += B * Y;
  }
  cout << ans <<endl;
}
