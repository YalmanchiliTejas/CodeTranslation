#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;


int main()
{
  int R1,R2;
  cin>>R1>>R2;
  double a=R1*R2,b=R1+R2;

  double R3=a/b;

  cout<<fixed<<setprecision(6)<<R3<<endl;
  return 0;
}
