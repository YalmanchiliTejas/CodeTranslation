#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

bool check_blank_col(vector<string> &v, int col) {
  bool f = true;
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it->at(col) != '.')
      f = false;
  }
  return f;
}

void remove_col(vector<string> &v, int col) {
  for (auto it = v.begin(); it != v.end(); it++) {
    it->erase(col, 1);
  }
}

int main(void) {
  vector<string> v;
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    string x;
    cin >> x;
    if (x != string(w, '.'))
      v.push_back(x);
  }
  for (int i = 0; i < v.begin()->size(); i++) {
    if (check_blank_col(v, i)) {
      remove_col(v, i);
      i = -1;
    }
  }
  for (auto i = v.begin(); i != v.end(); i++) {
    std::cout << *i << std::endl;
  }
  return 0;
}
