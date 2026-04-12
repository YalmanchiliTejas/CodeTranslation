#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> vec(1);
  //for (int i = 0;i < 3;i++) {
  //  cin >> vec.at(i);
  //}
  cin >> vec.at(0);

  if (vec.at(0) == "AAA") {
    cout << "No" << endl;
  } else if (vec.at(0) == "BBB") {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  
#if 0
  if (vec.at(0) == "A" && vec.at(1) == "A" && vec.at(2) == "A") {
    cout << "No" << endl;
  } else if (vec.at(0) == "B" && vec.at(1) == "B" && vec.at(2) == "B") {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
#endif
}
