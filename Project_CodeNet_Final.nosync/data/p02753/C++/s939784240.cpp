#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  char a;
  cin >> n;
  a = n[0];
  for(int i=1;i<n.size();i++){
    if(a!=n[i]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}