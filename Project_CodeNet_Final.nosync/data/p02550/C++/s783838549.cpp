#include <iostream>
#include <cstdint>
#include <unordered_map>

using namespace std;

int main() {
  uint64_t n, x, m;
  cin >> n >> x >> m;
  uint64_t seq[100010] = {};
  uint64_t len;
  uint64_t head;
  {
    uint64_t i = 0;
    unordered_map<uint64_t, uint64_t> map;
    while (map.count(x) == 0) {
      map[x] = i;
      seq[i] = x;
      x = (x * x) % m;
      ++i;
    }
    len = i;
    head = map[x];
  }
  uint64_t sl = 0;
  for (uint64_t i = head; i < len; ++i) {
    sl += seq[i];
  }
  uint64_t s = 0;
  if (n < head) {
    for (uint64_t i = 0; i < n; ++i) {
      s += seq[i];
    }
  } else {
    for (uint64_t i = 0; i < head; ++i) {
      s += seq[i];
    }
    uint64_t cl = (n - head) / (len - head);
    uint64_t tail = (n - head) % (len - head);
    s += sl * cl;
    for (uint64_t i = head; i < head + tail; ++i) {
      s += seq[i];
    }
  }

  cout << s << endl;
}
