#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  int Ac = 0;
  int Bc = 0;
  for(int i = 0; i < 3 ; i ++)
  {
    if(S[i] == 'A'){Ac++;}
    else if(S[i] == 'B'){Bc++;}
  }
  if(Ac == 0 || Bc == 0){ cout << "No" << endl;}
  else{ cout << "Yes" << endl;}
}