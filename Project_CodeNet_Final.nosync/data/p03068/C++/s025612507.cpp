#include <iostream>
using namespace std;

int main(){
  int n;
  string s;
  int k;
  cin >> n >> s >> k;
  char x = s[k - 1];
  for (int i = 0; i < n; i++){
    if (s[i] != x){
      s[i] = '*';
    }
  }

  for (int i = 0; i < n; i++){
    cout << s[i];
  }
  cout << endl;
  return 0;
}
