
/* Preprocess */
#include <bits/stdc++.h>

/* Field */
using namespace std;

/* Function */
int main (void) 
{

  int r, g, b;
  int num;
  string ans;

  cin >> r;
  cin >> g;
  cin >> b;

  num = r*100 + g*10 + b;

  if(num%4 == 0)
  {
    ans = "YES";
  }
  else
  {
    ans = "NO";
  }
  
  cout << ans << endl;


  return 0;

}