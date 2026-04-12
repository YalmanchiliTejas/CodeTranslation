#include <iostream>
#include <string>
using namespace std;
int main()
{
  int A,B,C;
  cin >>A>>B>>C;
  int X,Y;
  cin>>X>>Y;
  int P,Q,R;
  P = A*X+B*Y;
  if(X>Y) 
  {
    Q = 2*C*X;
    R = 2*C*Y+(X-Y)*A;
  }
  if(X<=Y) 
  {
    Q = 2*C*X+(Y-X)*B;
    R = 2*C*Y;
  }
  if(P<Q&&P<R) cout << P << endl;
  if(Q<=P&&Q<=R) cout << Q << endl;
  if(R<P&&R<Q) cout << R << endl;
  return 0;
}
 