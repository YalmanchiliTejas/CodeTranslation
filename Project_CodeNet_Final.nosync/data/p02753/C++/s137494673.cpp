#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

int main(){
  char tmp[3];
  cin >> tmp[0] >> tmp[1] >> tmp[2];
  string ret="No";
  if(tmp[0]!=tmp[1]) ret="Yes";
  if(tmp[1]!=tmp[2]) ret="Yes";
  if(tmp[2]!=tmp[0]) ret="Yes";  
  cout << ret << endl;
  return 0;
}
