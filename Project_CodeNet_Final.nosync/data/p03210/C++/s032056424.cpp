#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  int x;
  cin >> x;

  if(x == 3 || x == 5 || x == 7){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
