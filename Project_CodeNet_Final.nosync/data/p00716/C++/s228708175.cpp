#include <iostream>
#include <vector>
#include <algorithm>

int simple_interest(int initial_fund, int years, double interest_rate, int operation_charge);
int compound_interest(int initial_fund, int years, double interest_rate, int operation_charge);

int main(int argc, char const* argv[])
{
  int m;
  std::cin >> m;
  for (int case_num = 0; case_num < m; ++case_num) {
    int initial_fund, n_years, n;
    std::cin >> initial_fund >> n_years >> n;
    std::vector<int> results(n);
    for (int n_op = 0; n_op < n; ++n_op) {
      int simple_or_compound;
      double annual_interest_rate;
      int annual_operation_charge;
      std::cin >> simple_or_compound >> annual_interest_rate >> annual_operation_charge;
      results[n_op] = simple_or_compound
        ? compound_interest(initial_fund, n_years, annual_interest_rate, annual_operation_charge)
        : simple_interest(initial_fund, n_years, annual_interest_rate, annual_operation_charge);
    }
    std::cout << *std::max_element(results.begin(), results.end()) << std::endl;
  }
  return 0;
}

int simple_interest(int initial_fund, int years, double interest_rate, int operation_charge) {
  int cumulative_interest = 0;
  int fund = initial_fund;
  for (int y = 0; y < years; ++y) {
    cumulative_interest += fund * interest_rate;
    fund -= operation_charge;
  }
  return fund + cumulative_interest;
}

int compound_interest(int initial_fund, int years, double interest_rate, int operation_charge) {
  int fund = initial_fund;
  for (int y = 0; y < years; ++y) {
    int interest = fund * interest_rate;
    fund = fund + interest - operation_charge;
  }
  return fund;
}