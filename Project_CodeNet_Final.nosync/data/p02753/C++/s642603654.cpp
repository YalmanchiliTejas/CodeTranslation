#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;
typedef long long ll;

#define MAX_N 1000000
#define INF 1000000

int a[MAX_N];
int b[MAX_N];


int main() {

  // ---------------------
  // Input
  
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  char c[3];
  
  for (int i = 0; i < 3; i++) {
    c[i] = S[i];
  }

  // ---------------------
  // 

  if(c[0] == c[1] && c[1] == c[2]) cout << "No" << endl;
  else  cout << "Yes" << endl;

  return 0;
  
}
