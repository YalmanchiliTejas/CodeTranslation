#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  string s;
  cin >> n >> s >> k;
  int i;
  for(i = 0; i < n; i++)
  {
    if(s.at(i) == s.at(k-1))
    {
      cout << s.at(k-1);
    }
    else
    {
      cout << '*';
    }
  }
  cout << endl;
}