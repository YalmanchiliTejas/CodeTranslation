#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  char c; cin >> c;
  char vo[5] = {'a', 'i', 'u', 'e', 'o'};
  
  string result = (find(vo,vo+5,c)!=vo+5) ? "vowel" : "consonant";
  cout << result << endl;
  return 0;
}