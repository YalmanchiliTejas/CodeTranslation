#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string q;
  cin >> q;
  if(q.at(0) == q.at(1)) {
    if(q.at(1) == q.at(2)) {
      cout << "No" << endl;
    }
    else{
      cout << "Yes" << endl;
  }
  }
  else {
    cout << "Yes" << endl;
  }
}