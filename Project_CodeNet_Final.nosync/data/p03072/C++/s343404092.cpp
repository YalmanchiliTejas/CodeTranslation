#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include<cstdio>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
// #define ALLR(obj) (obj).rbegin(), (obj).rend()
#define BIT(n) (1LL << (n))

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  int toph = 0;
  int res = 0;
  rep(i, n) {
    int h;
    cin >> h;
    
    if (h >= toph) {
      ++res;
    }
    
    toph = max(h, toph);
  }
  
  cout << res;
}
