#include <bits/stdc++.h>
using namespace std;

int main() {
   long long A,B,C,X,Y;
   cin >> A >> B >> C >> X >> Y;
   if (A>=2*C && B>=2*C) cout << 2*C*max(X,Y) << endl;
   else if (A+B<=2*C) cout << A*X+B*Y << endl;
   else if (X>Y) {
       if (A<2*C) cout << 2*C*Y+A*(X-Y) << endl;
       else cout << 2*C*X << endl;
   }
   else {
       if (B<2*C) cout << 2*C*X+B*(Y-X) << endl;
       else cout << 2*C*Y << endl;
   }
}