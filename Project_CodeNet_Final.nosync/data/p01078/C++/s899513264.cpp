#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int main()
{
  double n, m;
  cin >> m >> n;
  cout << fixed << setprecision(10) << m * sin(PI/m) * cos(n*PI / m) / cos((n - 1) * PI / m) << endl;
}