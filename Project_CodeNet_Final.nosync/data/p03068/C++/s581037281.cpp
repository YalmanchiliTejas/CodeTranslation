#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int n,k;
  string s;
  cin >> n;
  cin >> s;
  cin >> k;
  char rem;
  rem = s[k-1];
  
  for (int i =0; i < n; i++){
    if (!(s[i] == rem)){
      s[i] = '*';
    }
  }
  cout << s;
}
