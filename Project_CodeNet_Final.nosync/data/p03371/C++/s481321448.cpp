#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
  long A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  int z = min(X,Y);
  cout << min({A*X+B*Y, 2*C*z+A*(X-z)+B*(Y-z), 2*C*max(X,Y)}) << endl;
}