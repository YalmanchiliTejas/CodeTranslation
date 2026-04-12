#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int set = min(A+B,C+C);
  int manyp = max(X,Y);
  int minp  = min(X,Y);
  int summin= minp*set;
  if(minp==X){
    summin+=(Y-minp)*B;
  }else{
    summin+=(X-minp)*A;
  }
  int summax= manyp*set;
  cout << min(summax,summin) << endl;
}
