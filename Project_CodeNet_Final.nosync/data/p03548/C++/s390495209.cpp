#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int X, Y, Z;
  cin >> X >> Y >> Z;

  int ans = 0;
  int length = 0;

  while(length <= X){
    ans++;
    length = Y*ans + Z*(ans+1);    
  }
  cout << ans-1 <<endl;
  
  return 0;
}