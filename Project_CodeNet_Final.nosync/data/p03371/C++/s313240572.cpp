#include<iostream>
#include <array>
#include <vector>
#include <algorithm>
#include "math.h"
using namespace std;

int main() {
  int A, B, AB, AN, BN;
  cin >> A >> B >> AB >> AN >> BN;
  if (AN > BN) {
    std::swap(AN, BN);
    std::swap(A, B);
  }
  std::vector<int> plans;
  plans.push_back(BN * 2 * AB);
  plans.push_back(A * AN + B * BN);
  if (AN != BN) {
    plans.push_back(AN * 2 * AB + (BN - AN) * B);
    // plans.push_back((AN - (BN - AN)) * A + (BN - AN) * AB * 2);
  }
  int min = *std::min_element(plans.begin(), plans.end());
  std::cout << min;
  return 0;
}