#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()
#define let auto const

template<typename... Types>
struct dynarr: std::vector<Types...> {
  using std::vector<Types...>::vector;
  using size_type = typename std::vector<Types...>::size_type;
  auto&& operator[](size_type i) { return this->at(i); }
  auto&& operator[](size_type i) const { return this->at(i); }
};

int main() {
  vector<i64> a(12);
  rep(i,0,12) cin >> a[i];
  sort(all(a));
  vector<i64> b;
  rep(i,0,4) b.push_back(a[0]);
  rep(i,0,4) b.push_back(a[4]);
  rep(i,0,4) b.push_back(a[8]);
  if(a == b) {
    cout << "yes" << endl;
  }
  else {
    cout << "no" << endl;
  }
}

