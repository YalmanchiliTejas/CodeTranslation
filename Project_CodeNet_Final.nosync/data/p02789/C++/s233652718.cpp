#include <iostream>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(void) {
  int n, m;
  cin >> n >> m;
  if(n - m != 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}