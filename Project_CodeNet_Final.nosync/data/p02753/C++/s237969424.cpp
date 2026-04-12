#include <bits/stdc++.h>
using namespace std;

int main() {
  char s1, s2, s3; 
  cin >> s1 >> s2 >> s3;
  if (s1 != s2 && s1 != s3)
    cout << "Yes" << endl;
  else if (s1 != s2 && s2 != s3)
    cout << "Yes" << endl; 
  else if (s1 != s3 && s2 != s3)
    cout << "Yes" << endl;
  else cout << "No" << endl;
}