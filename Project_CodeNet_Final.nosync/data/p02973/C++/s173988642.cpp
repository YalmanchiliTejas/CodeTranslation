#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define all(f,c,...) (([&](decltype((c)) cccc) { return (f)(begin(cccc), end(cccc), ## __VA_ARGS__); })(c))

int main() {
  int N; cin >> N;
  deque<int> color;
  for(int i=0;i<N;++i) {
    int a; cin >> a;
    auto it = all(lower_bound, color, a);
    if (it == color.begin()) color.push_front(a);
    else *(it-1) = a;
  }
  cout << color.size() << endl;

  return 0;
}
