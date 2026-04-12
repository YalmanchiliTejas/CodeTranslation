#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>
#include <math.h>
#include <stdint.h>
#include <bitset>
#include <iomanip>

using namespace std;


int main() {
  int N, M;
  cin >> N >> M;

  string result = "No";
  if(N==M) {
    result = "Yes";
  }

  cout << result << endl; 
}