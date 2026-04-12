#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, T, ans;
  cin >> N;
  T=(N-(N%15))/15;
  ans=800*N-200*T;
  cout << ans << endl;
}
