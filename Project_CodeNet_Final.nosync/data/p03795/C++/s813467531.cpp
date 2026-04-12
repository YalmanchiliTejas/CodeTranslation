#include<iostream>
#include<string>
#include<map>
#include<stack>

using namespace std;

int main() {
  int n;
  cin >> n;
  int x = 200 * (n / 15);
  int y = n * 800;
  cout << y - x << endl;
  return 0;
}
