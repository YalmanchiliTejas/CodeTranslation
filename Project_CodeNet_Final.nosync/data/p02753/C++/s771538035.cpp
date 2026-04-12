#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  char ch;
  int na = 0, nb = 0;
  for (int i = 0; i < 3; i++)
  {
    cin >> ch;
    if ('A' == ch) na++; else nb++;
  }
  cout << ((na && nb) ? "Yes" : "No") << endl;
  return 0;
}