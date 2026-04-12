#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y,P,score;
  cin >> A >> B >> C >> X >> Y;
  score=X*A+Y*B;
  for(int i=0;i<max(X,Y)+1;i++){
    P= 2*i*C + max(0,(X-i)*A) + max(0,(Y-i)*B);
    score=min(score,P);
  }
  cout << score << endl;
}