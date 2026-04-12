#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

//#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  x -= z;
  int n = x/(y+z);
  int m = x%(y+z);

  cout << n << endl;

}
