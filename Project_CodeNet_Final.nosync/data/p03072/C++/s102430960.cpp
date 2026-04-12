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

using ll = long long int;

int main(void) {
  int n;

  cin>>n;
  vector<int> v(n);
  for(int i=0; i<n; i++) {
    cin>>v[i];
  }
  int c=0;
  for(int i=0; i<n; i++) {
    bool f=true;
    for(int j=0; j<i; j++) {
      if(v[i]<v[j])
	f=false;
    }
    if(f)
      c++;
  }
  std::cout << c << std::endl;
  return 0;
}

