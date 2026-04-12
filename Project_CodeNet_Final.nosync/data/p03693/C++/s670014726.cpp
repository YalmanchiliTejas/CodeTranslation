#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main(){

  //initialization
  int r, g ,b;
  int ans;

  //input data
  cin  >> r >> g >> b;

  //solver
  ans = ((r * 100) + (g * 10) +  b) % 4;
  if(ans == 0){
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}
