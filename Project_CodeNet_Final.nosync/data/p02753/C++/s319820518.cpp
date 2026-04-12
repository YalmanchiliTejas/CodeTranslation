#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> vec(3);
  for (int i = 0;i < 3;i++) {
    cin >> vec.at(i);
  }
  
  string s1{vec.at(0)};
  string s2{vec.at(1)};
  string s3{vec.at(2)};
  
  if (s1 == "A" && s2 == "A" && s3 == "A") {
    cout << "No" << endl;
  } else if (s1 == "B" && s2 == "B" && s3 == "B") {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
