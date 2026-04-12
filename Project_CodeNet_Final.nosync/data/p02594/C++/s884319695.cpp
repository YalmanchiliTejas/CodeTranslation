#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = N; i >= 0; i--)

template<typename Container>
bool include(const Container& c, const typename Container::value_type& v) {
  return ( c.end() != std::find(c.begin(),c.end(),v) );
}

template<class T>
vector<T> unique_vec(const vector<T> &v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}

int main() {
  int X;
  cin >> X;

  if (X >= 30) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;

  return 0;
}