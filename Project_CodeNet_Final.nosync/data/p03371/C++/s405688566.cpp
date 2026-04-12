#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   int A,B,C,X,Y;
   cin >> A >> B >> C >> X >> Y;
 
   if(A+B <= 2*C){
       cout << A*X + B*Y <<endl;
   }
   else{
       int maxv = max(X,Y);
       int l,r;
       l = 2 * C * maxv;
       if(maxv == X) r = 2 * C * Y + (X - Y) * A;
       else r = 2 * C * X + (Y - X) * B;
       cout << min(l,r) << endl;
   }
}