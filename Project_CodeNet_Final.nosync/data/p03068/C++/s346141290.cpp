#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main(int argc,char** argv){
  int n,k;
  string s;
  char a;
  cin >> n;
  cin >> s;
  cin >> k;
  a = s[k-1];
  for(int i = 0; i < n; i++){
    if(s[i] == a){ cout << a;}
    else{cout << '*';}
  }
  cout << endl;
  return 0;
}

