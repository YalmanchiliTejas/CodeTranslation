#include<iostream>
using namespace std;
int main()
{
  int r1,r2;
  double r3;
  cin >> r1 >> r2;
  r3 = 1.0/(1.0/r1+1.0/r2);
  printf("%.8lf\n",r3);
  return 0;
}
