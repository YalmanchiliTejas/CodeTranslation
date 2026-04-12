#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

ll gcd(ll a, ll b) {
  ll tmp;
  if ( b > a) {
    tmp = a;
    a = b;
    b = tmp;
  }
  while (a % b !=0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main(void) {
  int n, m;
  cin>>n>>m;
  int e[10][10];
  for(int i=0; i<10; i++) {
    for(int j=0; j<10; j++) {
      e[i][j] = 0;
    }
  }
  for(int i=0; i<m; i++) {
    int x, y;
    cin>>x>>y;
    e[x][y] = 1;
    e[y][x]= 1;
  }
  vector<int> v;
  for(int i=2; i<=n; i++) {
    v.push_back(i);
  }
  int cnt=0;
  do {
    int prev = 1;
    bool f = true;
    for(auto &it : v) {
      if(!e[prev][it]) {
	f = false;
	break;
      }
      prev = it;
    }
    if(f)
      cnt++;
  }while(next_permutation(v.begin(), v.end()));
  std::cout << cnt << std::endl;
  return 0;
}

