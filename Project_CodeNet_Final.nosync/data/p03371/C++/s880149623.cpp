#include <iostream>
#include <vector>
using namespace std;
int main(void){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  int cost = 0;
  if(X<Y){
    int cost1 = A*X +B*X;
    int cost2 = C*2*X;
    
    cost = min(cost1,cost2);
    int rest = Y-X;
    cost1 = rest * B;
    cost2 = rest * 2 * C;
    cost += min(cost1,cost2);
  } else {
    int cost1 = A*Y +B*Y;
    int cost2 = C*2*Y;
    
    cost = min(cost1,cost2);
    int rest = X-Y;
    cost1 = rest * A;
    cost2 = rest * 2 * C;
    cost += min(cost1,cost2);
  }
  
  cout << cost << endl;
}
