#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007

int main() {
  int n, x;
  cin >> n >> x;
  pair<long long, long long> v;
  v.second = x;
  v.first = 0;
  for (int i = 1; i < n; i++) {
    cin >> x;
    v.first = (v.first + (v.second * x) % mod) % mod;
    v.second += x;
    v.second %= mod;
  }
  cout << v.first << endl;
}
