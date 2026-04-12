#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int r,g,b;
  cin >> r >> g >> b;
  int total = r * 100 + g * 10 + b;
  if(total % 4 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}