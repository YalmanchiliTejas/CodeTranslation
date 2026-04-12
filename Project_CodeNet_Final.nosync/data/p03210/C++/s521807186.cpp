#include <bits/stdc++.h>

#define copy(from, to) copy(from.begin(), from.end(), back_inserter(to));
#define sort(a) sort(a.begin(), a.end())

typedef long long ll;
using namespace std;

template<class T>
void load(vector<T> &v, int n) {
  for (int i = 0; i < n; ++i) {
    T t;
    cin >> t;
    v.push_back(t);
  }
}

int main() {
  int x;
  cin >> x;
  if (x == 3 || x == 5 || x == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}