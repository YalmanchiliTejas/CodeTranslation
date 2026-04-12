#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdint>
using namespace std;


uint64_t find_idx(vector<uint64_t> & v, uint64_t val) {
  uint64_t a = 0;
  uint64_t b = v.size();
  while (b > a) {
    uint64_t mid = (b + a) / 2;
    if (v[mid] < val) {
      b = mid;
    } else {
      a = mid + 1;
    }
  }

  return a;
}


int main()
{
  uint64_t n;

  cin >> n;
  vector<uint64_t> v;
  vector<uint64_t> s;
  v.resize(n + 1);
  for (uint64_t i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  for (uint64_t i = 1; i <= n; ++i) {
    auto j = find_idx(s, v[i]);
    if (j >= s.size()) {
      s.push_back(v[i]);
    } else {
      s[j] = v[i];
    }
  }
  cout << s.size() << endl;

  return 0;
}

