#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

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
  int n;
  cin>>n;
  vector<int> v;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    int x;
    cin>>x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int j=0;
  for(int i=2; i<n; i+=2) {
    a[i] = v[j];
    j++;
  }
  a[0] = v[j];
  j = n-1;
  for(int i=1; i<n; i+=2) {
    a[i] = v[j];
    j--;
  }
  ll ans0=0;
  for(int i=0; i<n-1; i++) {
    ans0+=abs(a[i]-a[i+1]);
  }
  sort(v.rbegin(), v.rend());
  j=0;
  for(int i=2; i<n; i+=2) {
    a[i] = v[j];
    j++;
  }
  a[0] = v[j];
  j=n-1;
  for(int i=1; i<n; i+=2) {
    a[i] = v[j];
    j--;
  }
  ll ans1 = 0;
  for(int i=0; i<n-1; i++) {
    ans1+=abs(a[i]-a[i+1]);
  }
  std::cout << max(ans0, ans1) << std::endl;
  return 0;
}

