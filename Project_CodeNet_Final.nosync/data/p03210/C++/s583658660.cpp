#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<tuple>
#include<vector>
#include<map>
#include<numeric>
#include<limits>
#include<type_traits>
using namespace std;


int main(void){
  int X;
  cin >> X;
  if(X == 3 || X == 5 || X == 7){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
  return 0;
}
