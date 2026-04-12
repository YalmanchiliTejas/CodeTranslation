#include<iostream>
#include<iomanip>
#include<limits>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>

#define big ((long long)(1e9)+7)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  int a = 0;
  int b = 0;
  for(int i = 0;i < s.size();i++)
  {
    if(s.at(i) == 'A')
    {
      a++;
    }
    if(s.at(i) == 'B')
    {
      b++;
    }
  }
  if(a == 2 || b == 2)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
