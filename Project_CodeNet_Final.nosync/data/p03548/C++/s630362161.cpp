#include <bits/stdc++.h>

using namespace std;


ifstream fin("date.in");
ofstream fout("date.out");

const int Nmax = 1e6 + 50;

int main()
{
  int x, y, z;

  cin >> x >> y >> z;

  int sum = y + z;

  cout << (x - z) / sum;
  
  return 0;
}