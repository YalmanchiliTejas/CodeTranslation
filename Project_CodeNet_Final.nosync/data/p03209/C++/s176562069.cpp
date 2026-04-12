#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long n, k;

long rec(long level, long step) {
  if (level == 0) return step > 0;
  
  const long total = (2ll << level) - 3;
  const long patty = (1ll << level) - 1;
  
  long sum = 0;
  if (step <= 1) return sum;
  --step;
  if (step <= total) return sum + rec(level - 1, step);
  step -= total;
  sum += patty;
  if (step <= 1) return sum + step;
  --step;
  ++sum;
  if (step <= total) return sum + rec(level - 1, step);
  sum += patty;
  step -= total;
  return sum;
}

int main() {
  cin >> n >> k;
  cout << rec(n, k) << endl;
}
