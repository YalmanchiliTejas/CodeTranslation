#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;

  int count=0;
  // ここにプログラムを追記
  for (int i=1;i<5;i++)
  {
    if(c=='a')
      count += 1;
    else if(c=='i')
      count += 1;
    else if(c=='u')
      count += 1;
    else if(c=='e')
      count += 1;
    else if(c=='o')
      count += 1;
  }

  if (count==0)
    cout << "consonant" << endl;
  else
    cout << "vowel" << endl;
}