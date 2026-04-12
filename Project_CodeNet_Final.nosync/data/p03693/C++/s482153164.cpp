#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <typeinfo>

using namespace std;

int main (){
  string r,g,b,ans;
  cin >> r >> g >>  b;
  ans = r+g+b;
  int a=atoi(ans.c_str());
  if (a%4==0){
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}
