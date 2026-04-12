#include<iostream>
using namespace std;

int main() {
  int a, b, ans;
  char sum;
  cin >> a >> b;
  for(int i = 0; i < a * b; i++) {
    cin >> sum;
    if(sum == '#') ans++;
  }
  cout << (a + b - 1 == ans ? "Possible" : "Impossible") << endl;
}
