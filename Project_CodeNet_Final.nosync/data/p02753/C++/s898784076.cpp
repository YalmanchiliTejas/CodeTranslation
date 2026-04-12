#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
  string str;
  cin >> str;
  int count = 0;
  rep(i, 3) {
    if (str.at(i) == 'A')
      count++;
  }
  if (count == 0 or count == 3)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}