#include <iostream>
#include <string>
using namespace std;

int main()
{
  string r, g, b;
  cin >> r >> g >> b;
  string s = "";
  s += r+g+b;
  if(stoi(s)%4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}