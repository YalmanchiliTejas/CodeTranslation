#include <iostream>
using namespace std;

int main()
{
  int x,y,z;
  cin >> x >> y >> z;
  int ret = 0;
  int sum = 0;
  while(sum <= x - z){
    sum += z + y;
	++ret;
  }
  if(0 < sum ){
    --ret;
  }
  cout << ret << endl;
  return 0;
}