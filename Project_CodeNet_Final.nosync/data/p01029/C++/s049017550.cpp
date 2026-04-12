#include <iostream>
#include <vector>

using namespace std;

class range {
private:
  struct Iterator {
    int val;
    int operator*() {return val;}
    bool operator!=(Iterator &itr) {return val < itr.val;}
    void operator++() {++val;}
  };
  Iterator i, n;
public:
  range(int n) : i({0}), n({n}) {}
  range(int i, int n) : i({i}), n({n}) {}
  Iterator &begin() {return i;}
  Iterator &end() {return n;}
};

template<class T> T at(vector<T> v, int i) {return v[(i % (int)v.size() + v.size()) % v.size()];}

int main() {
  int v, e;
  cin >> v >> e;
  char a[v];
  for (int i : range(v)) cin >> a[i];
  vector<int> edge[v];
  for (int i : range(e)) {
    int s, t;
    cin >> s >> t;
    edge[s].emplace_back(t);
    edge[t].emplace_back(s);
  }
  for (int i : range(v)) {
    if (a[i] != '?') continue;
    int bit = 0;
    for (const auto j : edge[i]) bit |= 1 << (a[j] - 'a');
    for (int j : range(26)) if (!(bit & 1 << j)) {
      a[i] = (char)(j + 'a');
      break;
    }
  }
  for (int i : range(v)) cout << a[i];
  cout << endl;
}
