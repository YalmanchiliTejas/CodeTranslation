#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#define input std::cin

using lint = long long int;
using vector = std::vector<lint>;
using string = std::string;

int main() {
  lint n, x, m; input >> n >> x >> m;
  vector sums; sums.reserve(m); sums.push_back(0);
  std::unordered_map<int, lint> seen;
  lint running = 0;
  for (int i=0; i<n; i++) {
	if (seen.count(x)) {
	  int prev = seen[x];
	  int period = (i+1)-prev;
	  n -= prev-1;
	  lint ans = sums[prev-1] + (running-sums[prev-1]) * (n/period) + (sums[prev-1+n%period]-sums[prev-1]);
	  running = ans;
	  break;
	}
	else {
	  running = (running + x);
	  seen.insert({x,i+1});
	  x = (x*x) % m;
	  sums.push_back(running);
	}
  }
  std::cout << running << std::endl;
}

