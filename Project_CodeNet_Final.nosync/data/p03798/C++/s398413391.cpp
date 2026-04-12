#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

static const int INF = 1 << 28;

#define D(x) cout << x << endl;
#define d(x) cout << x;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

long long n;
string S;
vll A;
bool found = false;

bool solve(int p, int q) {
  
  A[0] = p, A[1] = q;

  for (int i = 2; i < n; i++) {
    if (S[i - 1] == 'o') {
      A[i] = A[i - 2] * A[i - 1];
    } else {
      A[i] = A[i - 2] * A[i - 1] * -1;
    }
  }
  if ((S[n - 1] == 'o' && A[n - 2] * A[n - 1] == A[0]) || (S[n - 1] == 'x' && A[n - 2] * A[n - 1] * -1 == A[0])) {
    if ((S[0] == 'o' && A[n - 1] * A[0] == A[1]) || (S[0] == 'x' && A[n - 1] * A[0] * -1 == A[1])) {
      for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
          d('S');
        } else {
          d('W');
        }
      }
      D("");
      return true;
    }
  }
  return false;
}

int main() {
  cin >> n >> S;
  A.resize(n);

  if (solve(1, 1)) {
    return 0;
  } else if (solve(1, -1)) {
    return 0;
  } else if (solve(-1, 1)) {
    return 0;
  } else if (solve(-1, -1)) {
    return 0;
  } else {
    D(-1);
    return 0;
  }
}
