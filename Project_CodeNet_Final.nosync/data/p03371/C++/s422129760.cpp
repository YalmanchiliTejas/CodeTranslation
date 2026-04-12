#include<bits/stdc++.h>
using namespace std;

int main() {

  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  long long mini = 20000000000;

  for(int i = 0;i <= max(X,Y);i++) {
    long long sum = 2 * C * i + max(0,X - i) * A + max(0,Y - i) * B;
    mini = min(sum,mini);
  }

  cout << mini << endl;
}
