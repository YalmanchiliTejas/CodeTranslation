#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int n;

int main(){
  cin >> n;
  cout << n * 800 - n / 15 * 200 << endl;
  return 0;
}