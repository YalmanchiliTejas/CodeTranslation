#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <limits.h>
#include <cmath>
#include <queue>
#include <map>
#include <iomanip>
#include <random>
#include <fstream>
#define rep(i, n) for (int i = 0; i < n; i++)
#define pi 3.14159265358979323846
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
  ll r;
  while ((r = a % b))
  {
    a = b;
    b = r;
  }
  return b;
}

int main()
{

  int x; cin >> x;
  if (x==3 || x==5 || x==7){cout << "YES" << endl;}
  else {cout << "NO" << endl;}

  return 0;
}
