#include <iostream>

using namespace std;

int main()
{
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  int c = A*X+B*Y;
  for( int i=0;i<=2*max(X, Y);i+=2 )
    c = min(c, A*max(X-i/2, 0)+B*max(Y-i/2, 0)+C*i);
  cout << c << endl;
}
