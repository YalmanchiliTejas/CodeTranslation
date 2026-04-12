#include<iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int cnt = 0;
  for(int i = 0; i < 3; i++){
    if(s[i] == 'A'){
      cnt++;
    }
  }
  if(cnt == 3 || cnt == 0){
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
