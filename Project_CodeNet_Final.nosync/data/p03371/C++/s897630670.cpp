#include <iostream>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int cost=A*X+B*Y;
  for (int k=1; k<=100000; k++) {
    cost=min(cost,2*C*k+max(X-k,0)*A+max(Y-k,0)*B);
  }
  cout<<cost<<endl;
  return 0;
}