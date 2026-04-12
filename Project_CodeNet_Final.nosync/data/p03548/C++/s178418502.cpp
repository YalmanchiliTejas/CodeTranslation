#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int main (void) {
  int x,y,z;
  int ans;
  cin >> x >> y >> z;
  ans=(x-z)/(y+z);
  cout << ans;
}
