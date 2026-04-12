#include <iostream>
using namespace std;
int main()
{
  int x,y,z;
  cin >> x >> y >> z;
    for(int i=0; ; i++){
    if(x < z * (i+1) + y * i){
      cout << i - 1 << endl;
      return 0;
    }
    }
  
  return 0;
}