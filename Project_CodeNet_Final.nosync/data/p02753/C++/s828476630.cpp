#include <bits/stdc++.h>
using namespace std;

int main() {

  vector<char> data(3);
  for(int i=0;i<3;i++){
    cin >> data[i];
  }
  
  if(data[0]==data[1] && data[1]==data[2]) cout << "No" << endl;
  else cout << "Yes" << endl;
    
}