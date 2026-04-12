#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> h(n);
  int i, j;
  int ch = 0;
  int count = 0;
  for(i = 0; i < n; i++)
  {
    cin >> h.at(i);
  }
  for(i = 1; i < n; i++)
  {
    for(j = 0; j < i; j++)
    {
      if(h.at(i)<h.at(j))
      {
        ch = 1;
        break;
      }
    }
    if(ch == 0)
    {
      count++;
    }
    ch = 0;
  }
  cout << count+1 << endl;
}