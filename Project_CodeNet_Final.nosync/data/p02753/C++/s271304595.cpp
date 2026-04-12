#include<iostream>

using namespace std;

int main(){
  string str;
  bool hasA = false, hasB = false;

  cin >> str;

  for (int i = 0; i < (int)str.size(); i++){
    if (str[i] == 'A') {
      hasA = true;
    } else if (str[i] == 'B') {
      hasB = true;
    }
  }

  if (hasA && hasB) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
