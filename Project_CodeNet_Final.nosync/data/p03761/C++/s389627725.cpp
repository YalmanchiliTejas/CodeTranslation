#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
using namespace std;
#define ll int64_t
const long MOD = 1e9 + 7;
const long LINF = 1e13;
const long LLINF = 1e18;
const long ALPHABET = 26;

template <class T>
void Swap(T& r, T& l) {
  T tmp = r;
  r = l;
  l = tmp;
}



int main() {

  long n;

  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<long> count(ALPHABET, 1000);

  vector<vector<long>> stringCount(n, vector<long>(ALPHABET, 0));


  for (int i = 0; i < n; ++i) {
    for (auto v : s[i]) {
      stringCount[i][v - 'a']++;
    }
  }



  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < ALPHABET; j++) {
      count[j] = min(count[j], stringCount[i][j]);
    }
  }



  for (int i = 0; i < ALPHABET; ++i) {
    for(int j=0;j<count[i];j++){
      cout <<  (char)('a' + i)  ;
    }
  }



}


















