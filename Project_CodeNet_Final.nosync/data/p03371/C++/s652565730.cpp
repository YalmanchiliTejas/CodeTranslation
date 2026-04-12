#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){

  int A,B,C,X,Y;

  cin >> A;
  cin >> B;
  cin >> C;
  cin >> X;
  cin >> Y;

  if(2*C >= A+B){
    cout << A*X + B*Y << endl;
    return 0;
  }
  else if(2*C <= min(A,B)){
    cout << 2*C * max(X,Y) << endl;
    return 0;
  }
  else{
    
    cout << min(2*C*min(X,Y) + (X-min(X,Y))*A + (Y-min(X,Y))*B,2*C * max(X,Y)) << endl;
    return 0;
  }
  
  return 0;
}
