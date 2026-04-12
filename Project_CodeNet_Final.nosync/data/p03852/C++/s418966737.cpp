#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include <climits>
#define M 1000000007
#define ll long long
#define LIM 100000
using namespace std;
ll v[LIM];
int main() {
  string a;
  cin >> a;
  if (a == "a" || a == "i" || a == "u" || a == "e" || a == "o") {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
  return 0;
}
