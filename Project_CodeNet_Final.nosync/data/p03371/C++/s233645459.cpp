#include <iostream>
#include <vector>

using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int limit = max(X, Y) * 2;
  long long int budget = 1000000000;
  for(int c = 0; c <= limit; c+=2){
    long long int tmp = max(A * (X - c/2),0) + max(B * (Y - c/2),0) + c * C;
    budget = min(budget,tmp);
  }
  cout << budget;
}
