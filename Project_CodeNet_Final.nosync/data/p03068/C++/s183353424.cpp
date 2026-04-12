#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void){
  int n, k;
  string s;
  cin >> n >> s >> k;

  k --;

  char c;
  c = s.at(k);

  for(int i = 0; i < n; i ++){
    if(s.at(i) != c){
      s.at(i) = '*';
    }
  }

  cout << s << endl;

  return 0;
}
