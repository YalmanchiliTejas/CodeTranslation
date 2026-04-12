#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> vec(3);
  cin >> vec.at(0) >> vec.at(1) >> vec.at(2);
  
  if(vec.at(0) == vec.at(1) && vec.at(1) == vec.at(2)) {
    cout << "No" << endl;
  }
  
  else cout << "Yes" << endl;
}
 

