#include <iomanip>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  if (N == M)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
