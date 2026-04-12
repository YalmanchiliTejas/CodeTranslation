#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
#include <numeric>
using namespace std;

int main()
{
  int r,g,b;
  cin>>r>>g>>b;
  string ans="NO";
  if((10*g+b)%4==0) ans="YES";
  cout<< ans <<endl;
}
