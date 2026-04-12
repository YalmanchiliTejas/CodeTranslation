#include <bits/stdc++.h>
using namespace std;

int main() 
{
  string S;
  cin >> S;

  for (int i = 0; i < S.size(); i++) 
    {
    if (S.at(i) == 'a') 
    {
        cout << "vowel" << endl;
    }
    else if(S.at(i) == 'i')
    {
        cout << "vowel" << endl;
    }
    else if(S.at(i) == 'u')
    {
        cout << "vowel" << endl;
    }
    else if(S.at(i) == 'e')
    {
        cout << "vowel" << endl;
    }
    else if(S.at(i) == 'o')
    {
        cout << "vowel" << endl;
    }
    else
    {
       cout << "consonant" << endl;
    }
  }  
  return 0;
}