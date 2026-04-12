#include <iostream>

using namespace std;

bool test(char&,char&,char&,char);

int main()
{
  char S[3] = {0};
  
  cin >> S[1];
  cin >> S[2];
  cin >> S[3];
  
  if(test(S[1],S[2],S[3],'A'))
  {
    cout << "No" << endl;
  }
  else if(test(S[1],S[2],S[3],'B'))
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
}

bool test(char &a,char &b,char &c,char d)
{
  return a == d && b == d && c == d;
}
