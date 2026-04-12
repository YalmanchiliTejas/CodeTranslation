#include <iostream>
#include <vector>
#include <string>
#define input std::cin

using vector = std::vector<int>;
using lint = long long int;
using string = std::string;

int modulo = 1000000000 + 7;

int main() {
  int n; input >> n;
  vector nums (n);
  for (int &num : nums) {
	input >> num;
  }
  int ans = 0;
  int sum = 0;
  for (int i=nums.size()-1; i>=0; i--) {
	int prod = (nums[i] * (lint) sum) % modulo;
	ans = (ans + (lint)prod) % modulo;
	sum = (sum + (lint)nums[i])%modulo;
  }
  std::cout << ans << std::endl;
}

