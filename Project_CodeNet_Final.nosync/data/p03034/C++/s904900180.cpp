#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>

using namespace std;
long long mod = 1e9 + 7;
const int N = 3e5 + 500;

long long n, m, u, v, k, t, q, a, h;


int arr[N];


int main() {
   ios::sync_with_stdio(false);cin.tie(0);
   cin >> n;
   
   for (int i = 0; i < n; ++i) {
      cin >> arr[i];
   }
   
   long long best = 0;
   
   for (int diff = 1; diff < n; ++diff) {
      long long cur = 0;
      int x = diff, y = n - 1 - diff;
      while (x + diff < n - 1) {
         cur += arr[x];
         cur += arr[y];
         if (x >= y and ((n - 1) % diff) == 0) break;
         best = max(best, cur);
         x += diff;
         y -= diff;
      }
   }
   
   cout << best << endl;
}




