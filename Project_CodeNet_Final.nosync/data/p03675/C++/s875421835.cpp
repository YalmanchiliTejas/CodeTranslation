#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int i;
  for(i = 0; i < n; i++)
  {
    cin >> a.at(i);
  }
  if(n%2==0)
  {
    for(i = n-1; i >= 0; i -= 2)
    {
      if(i != n-1)cout << ' ';
      cout << a.at(i);
    }
    for(i = 0; i < n; i += 2)
    {
      cout << ' ' << a.at(i);
    }
    cout << endl;
  }
  else
  {
    for(i = n-1; i >= 0; i -= 2)
    {
      if(i != n-1)cout << ' ';
      cout << a.at(i);
    }
    for(i = 1; i < n; i += 2)
    {
      cout << ' ' << a.at(i);
    }
    cout << endl;
  }
}