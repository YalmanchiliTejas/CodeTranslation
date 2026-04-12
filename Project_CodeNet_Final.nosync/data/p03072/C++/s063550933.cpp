#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> h(n);
  for (int &i : h)
  {
    cin >> i;
  }
  int count = 1;
  bool b;
  for (int i = 1; i < n; i++)
  {
    b = true;
    for (int j = 0; j < i; j++)
    {
      if (h.at(j) > h.at(i))
      {
        b = false;
      }
    }
    if(b)
      count++;
  }
  cout << count << endl;
  return 0;
}