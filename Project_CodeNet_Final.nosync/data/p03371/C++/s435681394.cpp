#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;

int main() {
  ll A, B, C;
  int X, Y;
  cin >> A >> B >> C >> X >> Y;
  priority_queue<ll, vector<ll>, greater<ll>> value;
  for (int i = 0; i <= 100000; i++) {
    ll sum = i*2*C + max(0, X-i) * A + max(0, Y-i) * B;
    value.push(sum);
  }
  cout << value.top() << endl;
}
