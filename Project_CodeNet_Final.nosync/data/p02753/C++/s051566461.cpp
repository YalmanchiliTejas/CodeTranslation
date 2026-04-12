#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>

#define REP(i, n) for (int i = 0; i < (n); i++)
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9

using namespace std;
typedef long long ll;

int main() {
  string str;
  cin >> str;
  char c = str[0];

  REP(i, 3) {
    if (str[i] != c) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
