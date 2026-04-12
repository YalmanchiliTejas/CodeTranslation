#include<iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  int d = N/15;
  int x = N*800;
  int y = 200*d;
  cout << x-y << endl;
}