#include <iostream>
#include <vector>
using namespace std;

vector<int64_t> sheets(50);
vector<int64_t> patties(50);

int64_t f(int64_t n, int64_t x)
{
  if (n == 0) {
    return x <= 0 ? 0 : 1;
  } else if (x <= sheets[n - 1] + 1) {
    return f(n - 1, x - 1);
  } else {
    return patties[n - 1] + 1 + f(n - 1, x - 2 - sheets[n - 1]);
  }
}

int main()
{
  int64_t n, x;
  cin >> n >> x;
  sheets[0] = 1;
  patties[0] = 1;
  for (auto i = 1; i < n; i++) {
    sheets[i] = sheets[i - 1] * 2 + 3;
    patties[i] = patties[i - 1] * 2 + 1;
  }
  cout << f(n, x) << endl;
}
