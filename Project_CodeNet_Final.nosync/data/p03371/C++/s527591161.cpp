#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int A, B, C, X, Y;

int main(){
  cin >> A >> B >> C >> X >> Y;
  int a = min(A, 2 * C);
  int b = min(B, 2 * C);
  int ab = min(A + B, 2 * C);
  int res = 0;
  if(X > Y){
    res += Y * ab;
    res += (X - Y) * a;
  }else{
    res += X * ab;
    res += (Y - X) * b;
  }
  cout << res << endl;
}
