#include<iostream>
using namespace std;

int main(void) {
  int A, B, C, X, Y;
  cin>>A>>B>>C>>X>>Y;
  if (2*C > A+B) {
    cout<<A*X+B*Y<<endl;
    exit(0);
  }
  
  int M = max(X, Y);
  int m = min(X, Y);
  int cost1 = M*2*C;
  int cost2 = m*2*C + (M-m)*(M == X ? A:B);
  if (cost1 < cost2) cout<<cost1<<endl;
  else cout<<cost2<<endl;
  
  return 0;
}
