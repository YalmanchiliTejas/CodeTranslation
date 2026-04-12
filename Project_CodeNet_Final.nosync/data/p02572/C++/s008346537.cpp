#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n;
  long long sum,sa;
  sum = 0;
  sa = 0;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    sa += a.at(i);
  }
  for(int i=0;i<n;i++){
    sa -= a.at(i);
    long long si = sa;
    si %= 1000000007;
    sum += a.at(i)*si;
    sum %= 1000000007;
  }
  cout << sum << endl;
}
