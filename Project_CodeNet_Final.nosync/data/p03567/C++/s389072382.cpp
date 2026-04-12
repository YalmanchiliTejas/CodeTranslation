#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
string S;

int main() {
  INCANT;
  cin >> S;
  int N = S.size();
  bool flag = false;
  rep(i, N-1) {
    if (S[i]=='A' && S[i+1]=='C') flag = true;
  }
  string ans = flag?"Yes":"No";
  cout << ans << "\n";
  return 0;
}