#include <bits/stdc++.h>
using namespace std;

int main()
{
  string a, g, b;
  cin >> a >> g >> b;

  string agb = a + g + b;

  int num = stoi(agb);

  if (num % 4 == 0)
    cout << "YES" << endl;
  else 
    cout << "NO" << endl;

}
