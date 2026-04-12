#include <iostream>
using namespace std;
int main(){int A,B,C,X,Y,p;cin >> A >> B >> C >> X >> Y;
int a = X-Y;
cout << min(min(A*X+B*Y,2*C*min(X,Y)+ (a > 0 ? A * a : B * (Y - X))),2 * C * ( a > 0 ? X : Y));
}