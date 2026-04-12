#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, sum = 0, Nsum = 0;
  cin >> N;
  vector<ll> A(N);
  for(ll i = 0; i < N; i++) {
    cin >> A.at(i);
    if(i >= 1) {
      sum += ((Nsum % 1000000007) * (A.at(i) % 1000000007)) % 1000000007;
      sum %= 1000000007;
    }
    Nsum += A.at(i);
  }
  cout << sum << endl;
}