#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int N;
  vector<int> H;
  int temp;
  int ans;
  cin >> N;
  for(size_t i = 0; i < N; ++i)
  {
    cin >> temp;
    H.push_back(temp); 
  }
  for (size_t i = 0; i < H.size(); ++i)
  {
    bool can = true;
    for (size_t j = 0; j < i; ++j) {
      if (H[j] > H[i]) {
        can = false;
        break;
      }
    }
    if(can)
      ans++;
  }
  std::cout << ans << endl;
  return 0;
}