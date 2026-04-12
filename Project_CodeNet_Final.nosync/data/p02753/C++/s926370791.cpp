#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int a, b;
  a = 0;
  b = 0;

  for (int x = 0; x < 3; x++){
  	if (S.at(x) == 'A')
  		a++;
  	if (S.at(x) == 'B')
  		b++;	
  }
  if (a && b)
  	cout << "Yes" << endl;
  else 
  	cout << "No" << endl;

}
