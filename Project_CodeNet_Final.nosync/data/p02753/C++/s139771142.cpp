#include <bits/stdc++.h>

using namespace std;

int main()
{
  string a;
  cin >> a;
  for (int i = 0; i < 3; i++)
    {
       if (a[i] == 'A' && a[i+1] == 'B')
         {
         cout << "Yes";
         return 0;
          }
       else
         {if (a[i] == 'B' && a[i+1] == 'A')
         {
         cout << "Yes";
         return 0;
          }}
    }
  cout << "No";
}
