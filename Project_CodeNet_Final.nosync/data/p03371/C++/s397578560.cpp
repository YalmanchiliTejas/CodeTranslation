#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  long long sum1=0;
  long long sum2=0;
  long long sum3=0;
  
  sum1 = A*X + B*Y;
  
  for(int i=1;i<=max(X,Y);i++){
    sum2 = 2*i;
    sum3 = C*sum2 + A*max(0,X-i) + B*max(0,Y-i);
    sum1 = min(sum1,sum3);
  }
    
  cout << sum1 << endl;
  return 0;
}