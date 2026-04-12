#include <bits/stdc++.h>
using namespace std;
int main()
{
  long double r1;
  long double r2;
  cin>>r1>>r2;
  printf("%.15Lf\n", 1 / ((1 / r1) + (1 / r2)));
  return 0;
}