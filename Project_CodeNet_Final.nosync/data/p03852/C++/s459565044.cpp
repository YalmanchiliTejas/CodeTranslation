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
  string v = "aiueo";
  char c;
  cin >> c;
  for (int i = 0; i < 5; i++)
  {
    if (c == v.at(i))
    {
      cout << "vowel" << endl;
      break;
    }
    else
    {
      if (i == 4)
      {
        cout << "consonant" << endl;
      }
    }
  }
}