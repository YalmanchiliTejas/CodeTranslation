#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main()
{
  char c;
  cin >> c;
  
  if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u' )
  {
    cout << "vowel" << endl;
  }
  else
  {
    cout << "consonant" << endl;
  }

  return 0;
}