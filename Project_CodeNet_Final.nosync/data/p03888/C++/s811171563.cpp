#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
  double a,b,c;
  cin>>a>>b;
  c=(a*b)/(a+b);
  printf("%.10f\n",c);
  return 0;
}