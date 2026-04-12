#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main(int argc, const char * argv[]) {
  int n;
  cin >> n;

  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v.at(i);
  }
  
  int result = 1;
  int maxH = v.at(0);
  for(int i = 1; i < n; i++){
    if(v.at(i) >= maxH){
      maxH = v.at(i);
      result++;
    }
  }
  cout << result << endl;
  return 0;
}
