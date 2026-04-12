#include <iostream>
#include <vector>
using namespace std;
int main() {
  string a;
  cin >> a;
  if (a[0] == a[1] and a[1] == a[2]) {
    cout << "No";
  }else{
    cout << "Yes";
  }
  return 0;
}