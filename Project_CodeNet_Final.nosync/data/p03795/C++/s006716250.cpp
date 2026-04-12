#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int y=n/15;
  int y2=y*200;
  int x=n*800;
  int s=x-y2;
  //cout << y << endl;
  cout << s << endl;
  return 0;
}