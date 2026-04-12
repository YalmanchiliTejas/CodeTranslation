#include<iostream>
using namespace std;
int main(){
  int A,B,C;
  int X,Y;
  cin >> A >> B >> C >> X >> Y;
  if(X<Y){
    if(2*C<A+B && 2*C>B) cout << 2*C*X+B*(Y-X) << endl;
    if(2*C<A+B && 2*C<=B) cout << 2*C*Y << endl;
    if(2*C>=A+B) cout << A*X+B*Y << endl;
  }
  if(X>=Y){
    if(2*C<A+B && 2*C>A) cout << 2*C*Y+A*(X-Y) << endl;
    if(2*C<A+B && 2*C<=A) cout << 2*C*X << endl;
    if(2*C>=A+B) cout << A*X+B*Y << endl;
  }
  
}