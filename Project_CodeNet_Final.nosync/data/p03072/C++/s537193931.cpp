#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>
#include <vector>
#include <array>

using std::cout;
using std::cin;
using std::string;


int main()
{
  int n;
  cin >> n;

  std::vector<int> h(n);
  for(size_t i = 0; i < n; ++i)
  {
    cin >> h[i];
  }

  int num = 1;
  for(size_t i =1; i < h.size(); ++i)
  {
    bool error = false;
    for(size_t j = 0; j < i; ++j)
    {
      if(h[i] < h[j]){error  = true; break;}
    }
    if(!error) {num++;}
  }

  cout << num << "\n";
  return 0;
}
