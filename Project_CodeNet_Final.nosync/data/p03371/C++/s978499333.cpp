#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)



int main(){
  cin.tie(0); ios::sync_with_stdio(false);    // Magic for faster cin

  int A, B, C; int X, Y;
  cin >> A >> B >> C >> X >> Y;

  if(2*C>=A+B){
    cout << A*X + B*Y << endl;
    return 0;
  } else {
    int N = (X>Y)?Y:X;
    int hasuu = (X>Y)?((X-Y)*A):((Y-X)*B);
    int hasuu2 = 2*C*abs(X-Y);
    int h = (hasuu>hasuu2)?hasuu2:hasuu;
    cout << 2*N*C + h << endl;
  }

  return 0;
}
