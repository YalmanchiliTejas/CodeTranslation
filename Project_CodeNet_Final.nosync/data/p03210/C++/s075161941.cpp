#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <cmath>
#include <utility> // pair make_pair
#include <algorithm>
#include <functional>
#include <iomanip>
#include <climits> // LLONG_MAX, LLONG_MIN, INT_MIN, INT_MAX
#include <assert.h>

#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define ll long long
//#define int ll
#define INF INT_MAX/10
#define MOD 1000000007

using namespace std;
using Pi = pair<int, int>;
using Graph = vector<vector<int> >;
using WeightGraph = vector<vector<Pi> >;

int Input[100100];

int main() {
  int x; cin >> x;
  if (x == 3 || x == 5 || x == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
