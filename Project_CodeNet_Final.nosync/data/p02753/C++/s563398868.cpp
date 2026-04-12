#include<iostream>

using namespace std;

int main()
{
  string S;
  cin >> S;
  bool allA = S[0] == 'A' && S[1] == 'A' && S[2] == 'A';
  bool allB = S[0] == 'B' && S[1] == 'B' && S[2] == 'B';
  
  if (allA || allB)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
  
  return 0;
}