#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void){
  int n,k;
  string str;
  cin >> n;
  cin >> str;
  cin >> k;
  char c = str[k - 1];

  for(int i = 0; i != n; i++){
    if(str[i] == c)cout << c;
    else cout << '*';
  }
  cout << endl;
  return 0;
}