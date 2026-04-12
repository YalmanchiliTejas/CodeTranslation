#include <iostream>
#include <set>

using namespace std;

int main() {
  int ans = 0;
  multiset<int> s;
  s.insert(-100);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    auto v = s.lower_bound(a);
    v--;
    if (*v == -100) {
      s.insert(a);
    } else {
      s.erase(v);
      s.insert(a);
    }
  }
  s.erase(s.begin());
  cout << s.size() << endl;
}
