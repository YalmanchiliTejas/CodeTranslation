#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main() {
int a,b,c;
cin >> a >> b >> c;
if((100*a+10*b+c)%4==0){
  cout << "YES" << endl;
}
else{
  cout << "NO" << endl;
}

  return 0;
}
