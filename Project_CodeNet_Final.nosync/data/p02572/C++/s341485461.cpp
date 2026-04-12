#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n;
  long long sum,sa;
  sum = 0;
  sa = 0;
  cin >> n;
  vector<long long> a(n);
  for(long long i=0;i<n;i++){
    cin >> a.at(i);
    sa += a.at(i);
  }
  for(long long i=0;i<n;i++){
    sa -= a.at(i);
    sum += sa % 1000000007 * a.at(i);
    sum %= 1000000007;
  }
  cout << sum << endl;
}

