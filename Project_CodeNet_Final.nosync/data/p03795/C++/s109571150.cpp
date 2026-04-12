#include<iostream>
using namespace std;

int n;
int x, y;

int main(){
  cin >> n;
  x = 800 * n;
  y = 200 * (n / 15);
  cout << x - y << endl;
}
