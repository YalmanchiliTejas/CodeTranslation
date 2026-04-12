#include <iostream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 1<<15;
const ll MOD = 1e9+7;
const double EPS = 1e-9;


int main(int argc, const char * argv[]) {
  int N, K;
  string S;
  cin >> N >> S >> K;
  for (int i=0; i<N; i++){
    if (S[i] != S[K-1])
      S[i] = '*';
  }
  
  cout << S << endl;
  return 0;
}